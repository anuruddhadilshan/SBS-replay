# GEM low-level data/MC comparison

Standalone ROOT 6 C++ macro for Linux/WSL, matching the SBS replay environment; no generated `gep_tree_data` reader and no SBS library required. It reads replay outputs and does not change decoding, tracking, DB settings or your earlier comparison script.

## Run

Installed under `/home/anu-ubun/SBS-replay/scripts/gems`:

```sh
cd /home/anu-ubun/SBS-replay/scripts/gems
root -l -b -q 'GEM_lowlevel_data_MC_compare.C+("compare_ft.cfg","/path/to/output/ft_compare")'
```

Edit the data/MC file patterns in `compare_ft.cfg` first. Use **type-3 MC** for full-readout electronics comparisons. `compare_ft_selftest.cfg` is a five-event implementation test against the same MC file, not a real-data validation. Its saved histograms cover all 765 replay entries; `max_events` limits **only the tree loop**.

`input_source hist` skips reading events and compares saved GUI/noise/CM histograms. `combined` adds the tree diagnostics. `baseline_source saved` preserves original replay selections. `baseline_source tree` reconstructs the ordinary GUI definitions using the configured event cut/weight plus their `.odef` cuts. Some scalar module variables, notably `module.ontrack`, may be absent from your tree; affected definitions are explicitly skipped. Module-created noise/CM histograms always retain their saved selections.

## Plots implemented

- All **476 names** from the FT GUI, with exact `.odef` bins/selections in the supplied catalogue. Saved V all-channel ADC, corrected/raw ADC versus APV, and CM estimate versus APV are added.
- Empirical corrected-ADC core offset and width by APV: median and `(q84-q16)/2`, plus quantile bounds, mean profiles, and positive/negative visible-bin tail fractions beyond five core widths. These describe populated histogram cores; signals/background and histogram truncation can affect them. Core widths are not calibrated noise-sigma units. DB pedestal RMS is not treated as a measured noise distribution.
- Absolute six-sample and signed normalized waveforms; mean/median/16th/84th-percentile profiles; retained-pulse six-by-six Pearson correlations; early/late fractions; peak sample and peak fraction versus charge.
- Mean time/RMS versus charge, mean time versus physical APV group, charge sum versus maximum sample, configurable positive transport-rail indicators, and rail-conditioned waveforms.
- U/V strip and cluster multiplicity correlations, strip-index activity, retained strips per physical APV/event including empty APVs for normal views, retained-strip spacing, and charge versus source-file index.
- Existing cluster size versus charge, retained neighbor charge fraction versus distance from the cluster seed, neighbor timing difference and waveform correlation. The macro validates physical indices, contiguous bounds, seed membership and array lengths before constructing sharing plots. Rejected ambiguous associations are counted.
- Waveform comparisons in configurable charge and APV-occupancy bins for track-associated strips passing the signal cut. Tracks are signal proxies; no MC truth bookkeeping is used.

The tree views are `inclusive`, `ontrack`, `offtrack`, and `full_readout`. The last uses **per-strip** `BUILD_ALL_SAMPLES && !ENABLE_CM`. It still contains only strips retained after offline ZS. It cannot recover completely empty APVs or distinguish periodic full readout from CM-error-triggered readout. Its per-event yield is deliberately omitted; its waveform shapes remain available. For ordinary views, APV groups mean `physical strip index / 128`; no live-channel fraction is inferred.

## Selections and normalization

The file-list/cut blocks accept your existing configuration format. Multi-line event cuts are joined with `&&`; event cuts and weights evaluate formula instance 0, matching your existing macro. Use explicit `Sum$`, `Length$`, etc. when an event cut requires a reduction of an array. The legacy `sepctrometer` spelling is accepted with a warning; new configs use `detector sbs.gemFT`.

- Inclusive cuts default to `1`; track requirements would bias background/occupancy diagnostics.
- `data_signal_cut` / `mc_signal_cut` further restrict the **ontrack** view and conditional waveform bins. They do not filter the inclusive/offtrack/full-readout views, saved histograms or inclusive cluster-sharing plots.
- `best_track_only 1` additionally requires `strip.itrack == 0` for the ontrack proxy. With that option, offtrack includes strips associated with other tracks and should be interpreted accordingly.
- Weights must be finite and nonnegative; this is required for shape quantiles. Weighted raw counts use `Sumw2`. Saved replay histograms cannot be reweighted retrospectively.
- Display clones are unit-area densities over **visible bins**; under/overflow is preserved in raw histograms and reported in CSV. ROOT histograms remain unchanged. Profiles, correlations and quantile values are not area-normalized.
- Per-event plots divide raw counts by the sum of selected event weights. Ontrack plots use weights of selected events passing the signal cut, including events without a GEM track. Saved `.odef` rates use total replay entries and their original `.odef` selection. Saved pre-ZS marginals use shapes and actual sample counts, with no factor of 100.
- Zero-MC bins have ratio zero plus a separate validity mask; interpret that stored zero as undefined. Those bins are omitted from the PDF ratio points. Ratios use normal bin-error propagation. Derived quantile/correlation values do not carry a bootstrap uncertainty. Ratios of profile/value plots are aids to comparison and may be undefined near zero.

Different data/MC binnings/classes are reported and have no ratio. If any file is missing an optional plot input, that plot is excluded from the **whole dataset** to avoid silently comparing incomplete file coverage. Required strip index, axis and charge branches must exist for tree processing. `strict_optional 1` instead stops at the first missing optional input. An exception writes `_ERROR.txt` and an issues ledger; do not interpret output from a failed run.

## Inputs and replay output definitions

Saved GUI histograms must be enabled in the replay `.odef`. Module-created full-readout histograms must be populated by the appropriate replay mode/CM settings; object presence alone is insufficient. Empty populations are marked in CSV. Optional estimator-comparison histograms created by `plot_common_mode` are not compared automatically; the default CM comparison uses `hCommonModeMean_by_APV_[UV]`.

For the tree diagnostics, enable at least these variable patterns in the `.odef` (alongside the normal FT histogram definitions):

```text
block sbs.gemFT.m*.strip.*
block sbs.gemFT.m*.clust.*
block sbs.gemFT.m*.mc_input_mode
```

Preserve ordinary reconstructed ADC branches; do not substitute `goodADC*` arrays. The reader checks the actual numeric ROOT leaf types and lengths, including `ADCsamples.size() == 6 * istrip.size()`. Optional ontrack/itrack, timing, raw samples, flags and cluster fields are checked separately. Each file gets fresh leaf/formula bindings, so schema changes and file transitions cannot leave stale addresses. Expanded file lists are sorted and deduplicated.

The shipped catalogue is FT-specific. To refresh it after GUI/`.odef` changes:

```sh
python3 make_gem_lowlevel_catalog.py
```

For another detector, supply its GUI/`.odef` to that helper and set `--detector`, then use the resulting catalogue plus the correct `detector`, `nmodules` and `modules` configuration. The macro refuses to reuse a catalogue for a different detector. The helper currently accepts the module-level `th1d` GUI entries used by FT; extend it for a GUI containing `th2d` definitions.

## Files written

- `<prefix>.root`: `data/raw`, `mc/raw`, `data/shape`, `mc/shape`, `*/per_event`, `ratios`, `ratio_valid_masks`, plot metadata, input configuration and event counters. Per-X mean/median/quantile/core-width histograms are included.
- `<prefix>.pdf`: four plots per page; 2D comparisons have matched axes/colour scales. The example shows module 0 to keep browsing manageable; ROOT/CSV always include every configured module. Set `pdf_module -1` for all modules, `pdf_max_pages` to cap the PDF, or `make_pdf 0`.
  The `hADCpedsubU_allstrips_*` and `hADCpedsubV_allstrips_*` overlays use a logarithmic Y axis to display ADC tails; their ratio panels remain linear. Other overlays retain linear Y axes.
- `_preview.png`: the first page of plotted comparisons for quick layout inspection.
- `_summary.csv`: populations, flow fractions, means/RMS, quantiles, exposure and exact selection scope.
- `_differences.csv`: median difference, core-width ratio and integrated shape difference for comparable 1D counts. These are effect sizes, not independent-sample significance tests or unique diagnoses of simulator parameters.
- `_issues.csv`: missing inputs, incompatible bins and unavailable diagnostics.
- `_provenance.json`: exact files, cuts/weights, calibration labels, ROOT version and conditional-bin edges. Set meaningful calibration identifiers in your production config.

## Diagnostics requiring additional input

Unbiased quiet-channel temporal/cross-channel noise covariance, residual APV CM versus occupancy, and sub-threshold sharing wings require paired pre-ZS event records or Decode-time accumulators. Existing marginal histograms and retained strip arrays cannot reconstruct these quantities. Noise units and live-channel/dead-channel maps require an explicit calibration/mask reader; this version does not infer them. Trigger-phase and external sub-strip impact diagnostics also need validated metadata. These are separate extensions, not reconstruction studies.

The real farm files are not available locally. Validation here uses the supplied type-3 replay and synthetic fixtures; running against representative real replay files remains necessary before drawing physics conclusions.

To repeat the bounded implementation tests (requires Python `uproot`, `awkward` and `numpy`):

```sh
python3 test_gem_lowlevel_compare.py --mc-smoke
```
