#!/usr/bin/env python3
"""Bounded implementation tests: synthetic ROOT trees plus optional real MC smoke tests.
Run inside WSL. Does not alter replay, calibration, tracking or producer inputs.
"""
import argparse
import csv
import json
import os
from pathlib import Path
import subprocess
import shutil
import awkward as ak
import numpy as np
import uproot

p = argparse.ArgumentParser(description=__doc__)
p.add_argument('--macro-dir', default='/home/anu-ubun/SBS-replay/scripts/gems')
p.add_argument('--output', default='/home/anu-ubun/gep_sim/gem_compare_validation')
p.add_argument('--root', default='/home/anu-ubun/ROOT/root_install')
p.add_argument('--mc-smoke', action='store_true')
args = p.parse_args()
folder, outdir = Path(args.macro_dir), Path(args.output)
outdir.mkdir(parents=True, exist_ok=True)
env = os.environ.copy()
env['ROOTSYS'] = args.root
env['LD_LIBRARY_PATH'] = args.root+'/lib:'+env.get('LD_LIBRARY_PATH', '')

def run(cfg, prefix, success=True):
    log = outdir/(prefix+'.log')
    expr = f'GEM_lowlevel_data_MC_compare.C+("{cfg}","{outdir/prefix}")'
    with log.open('w') as stream:
        r = subprocess.run([args.root+'/bin/root', '-l', '-b', '-q', expr],
                           cwd=folder, env=env, stdout=stream, stderr=subprocess.STDOUT)
    if success:
        assert r.returncode == 0, log.read_text()[-4000:]
        assert not (outdir/(prefix+'_ERROR.txt')).exists()
    else:
        assert r.returncode != 0, 'Expected a clear failure'
        assert (outdir/(prefix+'_ERROR.txt')).stat().st_size > 0
    print(prefix, 'PASS', flush=True)

catalog = outdir/'fixture_catalog.tsv'
rows = [line for line in (folder/'GEM_lowlevel_catalog.tsv').read_text().splitlines()
        if line.split('\t')[0] in ('hsbs_gemFT_m0_ADCsumU_all',
                                    'hsbs_gemFT_m0_stripU_all',
                                    'hsbs_gemFT_m0_nclustU_all')]
assert len(rows) == 3
catalog.write_text('\n'.join(rows)+'\n')
prefix = 'sbs.gemFT.m0.'

def fixture(path, dtype='float64', malformed=False, missing=False):
    strip = [[10,11,12,8], [], [125,20,21,22]]
    is_u = [[1,1,1,0], [], [1,0,0,0]]
    charge = [[600,1200,300,900], [], [80,800,1600,400]]
    pulse = np.array([-.02,.02,.15,.45,.30,.10])
    sample = [[float(v) for q in event for v in pulse*q] for event in charge]
    if malformed: sample[0] = sample[0][:-1]
    raw = [list(v) for v in sample]
    if not malformed: raw[0][9] = 4095
    fields = {
        'strip.istrip': strip, 'strip.IsU': is_u, 'strip.ADCsum': charge,
        'strip.ADCmax': [[max(pulse*q) for q in v] for v in charge],
        'strip.ADCsamples': sample, 'strip.rawADCsamples': raw,
        'strip.Tmean': [[72]*4, [], [72]*4],
        'strip.Tsigma': [[22]*4, [], [22]*4],
        'strip.ontrack': [[1,1,1,0], [], [0,1,1,1]],
        'strip.itrack': [[0,0,0,-1], [], [-1,0,0,0]],
        'strip.BUILD_ALL_SAMPLES': [[1,1,1,0], [], [1]*4],
        'strip.ENABLE_CM': [[0,0,0,1], [], [0]*4],
        'strip.CM_GOOD': [[1]*4, [], [1]*4],
        'clust.clustu_strips': [[3], [], [1]],
        'clust.clustv_strips': [[1], [], [3]],
        'clust.clustu_adc': [[2100], [], [80]],
        'clust.clustv_adc': [[900], [], [2800]],
        'clust.clustu_istriplo': [[10], [], [125]],
        'clust.clustv_istriplo': [[8], [], [20]],
        'clust.clustu_istripmax': [[11], [], [125]],
        'clust.clustv_istripmax': [[8], [], [21]],
    }
    if missing:
        for field in ['strip.ADCsamples', 'strip.rawADCsamples']:
            fields.pop(field)
    schema = {prefix+k: 'var * '+dtype for k in fields}
    data = {prefix+k: ak.values_astype(ak.Array(v), np.dtype(dtype)) for k,v in fields.items()}
    for field, values in {'mc_input_mode': [3]*3, 'clust.nclustu': [1,0,1], 'clust.nclustv': [1,0,1]}.items():
        schema[prefix+field] = 'float64'; data[prefix+field] = np.array(values, dtype='float64')
    schema['event_id'] = 'int32'; data['event_id'] = np.arange(3, dtype='int32')
    schema['event_weight'] = 'float64'; data['event_weight'] = np.array([2,0,1], dtype='float64')
    with uproot.recreate(path) as f:
        t = f.mktree('T', schema)
        t.extend(data)

fixture(outdir/'fixture_a.root')
fixture(outdir/'fixture_b.root', 'float32')
fixture(outdir/'malformed.root', malformed=True)
fixture(outdir/'missing.root', missing=True)

def config(name, files, cut='event_id != 1', extra=''):
    text = '\n'.join(map(str, files))+'\nendDatlist\n'+'\n'.join(map(str, files))
    text += f'\nendMClist\n{cut}\nendcutDat\n{cut}\nendcutMC\n'
    text += f'''detector sbs.gemFT
nmodules 14
modules 0
catalog {catalog}
input_source combined
baseline_source tree
data_weight event_weight
mc_weight event_weight
mc_input_mode 3
saved_electronics 0
make_pdf 0
{extra}
endcfg
'''
    path = outdir/(name+'.cfg');path.write_text(text);return path

# Duplicate expansion must not double-count the first file; float/double leaves
# are rebound at the file transition. Both sides use the same controlled sample.
cfg = config('weighted', [outdir/'fixture_*.root', outdir/'fixture_a.root'])
run(cfg, 'weighted')
f = uproot.open(outdir/'weighted.root')
assert f['data/selected_entries'].member('fVal') == 4
assert f['data/selected_sum_weights'].member('fVal') == 6
assert f['data/raw/m0_U_inclusive_charge'].values(flow=True).sum() == 14
assert f['data/raw/m0_V_inclusive_charge'].values(flow=True).sum() == 10
assert f['data/raw/m0_U_inclusive_absolute_samples'].values(flow=True).sum() == 84
assert f['data/raw/hsbs_gemFT_m0_ADCsumU_all'].values(flow=True).sum() == 14
assert f['data/raw/m0_U_inclusive_apv_occupancy'].values(flow=True).sum() == 31*6
assert f['data/raw/m0_U_inclusive_neighbor_fraction'].values(flow=True).sum() == 12
assert f['data/raw/m0_U_full_readout_charge'].values(flow=True).sum() == 14
assert f['data/raw/m0_V_full_readout_charge'].values(flow=True).sum() == 6
assert 'data/per_event/m0_U_full_readout_charge' not in f
for key in f['data/raw'].keys(cycle=False):
    np.testing.assert_array_equal(f['data/raw/'+key].values(flow=True), f['mc/raw/'+key].values(flow=True))
for key in f['ratios'].keys(cycle=False):
    r, mask = f['ratios/'+key].values(flow=True), f['ratio_valid_masks/'+key].values(flow=True)
    np.testing.assert_allclose(r[mask>0], 1, atol=1e-12)
assert 'Deduplicated input' in (outdir/'weighted.log').read_text()

# Include the zero-strip, zero-weight event to validate dynamic empty arrays.
run(config('zero_strips', [outdir/'fixture_a.root'], cut='1'), 'zero_strips')
z = uproot.open(outdir/'zero_strips.root')
assert z['data/selected_entries'].member('fVal') == 3
assert z['data/raw/m0_U_inclusive_charge'].values(flow=True).sum() == 7

# Empty selections must stay empty and produce no NaN/Inf normalizations.
run(config('empty', [outdir/'fixture_a.root'], cut='0'), 'empty')
e = uproot.open(outdir/'empty.root')
assert e['data/selected_entries'].member('fVal') == 0
for key in e['data/shape'].keys(cycle=False):
    assert np.isfinite(e['data/shape/'+key].values(flow=True)).all()

# Missing optional fields are excluded, not drawn as spurious empty agreement.
run(config('missing', [outdir/'missing.root']), 'missing_result')
m = uproot.open(outdir/'missing_result.root')
assert 'data/raw/m0_U_inclusive_fraction_samples' not in m
assert 'missing six-sample arrays' in (outdir/'missing_result_issues.csv').read_text()

run(config('schema_change', [outdir/'fixture_a.root', outdir/'missing.root']), 'schema_change')
sc = uproot.open(outdir/'schema_change.root')
assert 'data/raw/m0_U_inclusive_fraction_samples' not in sc
assert sc['data/raw/m0_U_inclusive_charge'].values(flow=True).sum() == 14

run(config('malformed', [outdir/'malformed.root']), 'malformed_result', success=False)
assert 'Array length mismatch' in (outdir/'malformed_result_ERROR.txt').read_text()
run(config('bad_mode', [outdir/'fixture_a.root'], extra='mc_input_mode 2'), 'bad_mode', success=False)
assert 'MC input mode differs' in (outdir/'bad_mode_ERROR.txt').read_text()

# Input/output identity guard prevents an accidental output prefix from replacing
# the replay input after it has been read.
run(config('identity', [outdir/'fixture_a.root']), 'fixture_a', success=False)
assert 'would overwrite an input' in (outdir/'fixture_a_ERROR.txt').read_text()
assert uproot.open(outdir/'fixture_a.root')['T'].num_entries == 3

# Hist-only: incompatible data/MC binning, flow preservation, zero-denominator masks.
histname = 'hsbs_gemFT_m0_ADCsumU_all'
for side, bins in [('hist_a', 10), ('hist_b', 11)]:
    with uproot.recreate(outdir/(side+'.root')) as h:
        h[histname] = (np.arange(bins, dtype=float), np.linspace(0, 100, bins+1))
histcfg = outdir/'hist_bins.cfg'
histcfg.write_text(f'''{outdir/'hist_a.root'}
endDatlist
{outdir/'hist_b.root'}
endMClist
endcutDat
endcutMC
modules 0
catalog {catalog}
input_source hist
saved_electronics 0
make_pdf 0
endcfg
''')
run(histcfg, 'hist_bins')
h = uproot.open(outdir/'hist_bins.root')
assert histname not in h['ratios'].keys(cycle=False)
assert 'bins or classes differ' in (outdir/'hist_bins_issues.csv').read_text()

if args.mc_smoke:
    run(folder/'compare_ft_selftest.cfg', 'selftest')
    # Exercise every module and all 476 exact GUI names in a bounded event loop.
    actual = (folder/'compare_ft_selftest.cfg').read_text()
    actual = actual.replace('modules 0\n', '').replace('max_events 5', 'max_events 2').replace('make_pdf 1', 'make_pdf 0')
    cfg = outdir/'all_modules.cfg';cfg.write_text(actual)
    run(cfg, 'all_modules')
    a = uproot.open(outdir/'all_modules.root')
    gui = [line.split('\t')[0] for line in (folder/'GEM_lowlevel_catalog.tsv').read_text().splitlines() if not line.startswith('#')]
    assert len(gui) == 476
    assert all('data/raw/'+name in a for name in gui)
    for name in gui:
        np.testing.assert_array_equal(a['data/raw/'+name].values(flow=True), a['mc/raw/'+name].values(flow=True))
    assert a['data/raw/hADCpedsubU_allstrips_sbs_gemFT_m0'].member('fEntries') == 3968*6*765
    report = json.load(open(outdir/'all_modules_provenance.json'))
    assert all(v['selected'] == 2 and v['replay_entries'] == 765 for v in report['datasets'])
    assert len(list(csv.reader(open(outdir/'all_modules_issues.csv')))) == 5

print('All assertions passed. These tests validate the comparison implementation, not real-data physics agreement.')
