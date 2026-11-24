"""A simple pixel-difference baseline for aligned satellite GeoTIFF pairs.

This script segments changed pixels only. It does not infer whether a change
was caused by people or nature.
"""

from __future__ import annotations

import argparse
from pathlib import Path

import numpy as np
import rasterio


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--before", required=True, type=Path, help="Earlier aligned GeoTIFF")
    parser.add_argument("--after", required=True, type=Path, help="Later aligned GeoTIFF")
    parser.add_argument("--output", required=True, type=Path, help="Output binary change-mask GeoTIFF")
    parser.add_argument(
        "--threshold",
        type=float,
        default=0.08,
        help="Mean absolute reflectance difference threshold (default: 0.08)",
    )
    return parser.parse_args()


def check_same_grid(before: rasterio.io.DatasetReader, after: rasterio.io.DatasetReader) -> None:
    same_grid = (
        before.crs == after.crs
        and before.transform == after.transform
        and before.width == after.width
        and before.height == after.height
        and before.count == after.count
    )
    if not same_grid:
        raise ValueError(
            "Before and after rasters must have identical CRS, transform, dimensions, "
            "and band count. Reproject/resample them to a common grid first."
        )


def main() -> None:
    args = parse_args()
    if args.threshold < 0:
        raise ValueError("Threshold must be non-negative.")

    args.output.parent.mkdir(parents=True, exist_ok=True)

    with rasterio.open(args.before) as before, rasterio.open(args.after) as after:
        check_same_grid(before, after)

        before_data = before.read(masked=True).astype(np.float32)
        after_data = after.read(masked=True).astype(np.float32)
        before_mask = np.ma.getmaskarray(before_data)
        after_mask = np.ma.getmaskarray(after_data)
        valid = np.isfinite(before_data.data).all(axis=0)
        valid &= np.isfinite(after_data.data).all(axis=0)
        valid &= ~before_mask.any(axis=0)
        valid &= ~after_mask.any(axis=0)

        # Mean absolute difference across the selected, consistently ordered bands.
        score = np.abs(before_data.data - after_data.data).mean(axis=0)
        mask = np.full((before.height, before.width), 255, dtype=np.uint8)
        mask[valid] = (score[valid] >= args.threshold).astype(np.uint8)

        profile = after.profile.copy()
        profile.update(count=1, dtype="uint8", nodata=255, compress="lzw")
        with rasterio.open(args.output, "w", **profile) as destination:
            destination.write(mask, 1)

    valid_count = int(valid.sum())
    changed_count = int(((mask == 1) & valid).sum())
    changed_percent = (100.0 * changed_count / valid_count) if valid_count else 0.0
    print(f"Saved change mask: {args.output}")
    print(f"Changed valid pixels: {changed_count}/{valid_count} ({changed_percent:.2f}%)")
    print("This baseline detects change only; it does not assign a cause.")


if __name__ == "__main__":
    main()
