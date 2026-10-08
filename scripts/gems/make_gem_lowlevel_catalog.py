#!/usr/bin/env python3
"""Extract exact GUI names and .odef definitions for the standalone ROOT macro."""
import argparse
import re
from pathlib import Path

p = argparse.ArgumentParser(description=__doc__)
p.add_argument("--gui", default="../../onlineGUIconfig/sbs_gem_basic_gepFT.cfg")
p.add_argument("--odef", default="../../replay/replay_FTGEM_gep.odef")
p.add_argument("--detector", default="sbs.gemFT")
p.add_argument("--output", default="GEM_lowlevel_catalog.tsv")
args = p.parse_args()
token = args.detector.replace(".", "_")
names = sorted(set(re.findall(
    r"(?:h" + re.escape(token) + r"|hADCpedsub[UV]_allstrips_" + re.escape(token) + r")[A-Za-z0-9_]*",
    Path(args.gui).read_text())))
definitions = {}
for line in Path(args.odef).read_text().splitlines():
    match = re.match(r"^\s*th1d\s+(\w+)\s+", line)
    if match:
        definitions[match[1]] = line.strip()
rows = ["# name\tmodule\tmodule OR exact th1d .odef definition",
        f"# GUI: {args.gui}", f"# ODEF: {args.odef}"]
for name in names:
    m = re.search(r"_m(\d+)", name)
    if not m:
        raise ValueError(f"Cannot determine module: {name}")
    if name in definitions:
        definition = definitions[name]
    elif name.startswith("hADCpedsub"):
        definition = "module"
    else:
        raise ValueError(f"GUI histogram is missing from .odef: {name}")
    rows.append(f"{name}\t{m[1]}\t{definition}")
if not names:
    raise ValueError("GUI contains no matching histogram names")
Path(args.output).write_text("\n".join(rows) + "\n")
print(f"Wrote {len(names)} GUI entries to {args.output}")
