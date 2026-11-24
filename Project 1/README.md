# Project 1 - Satellite Change Detection and Cause Segmentation

## Problem

Given satellite imagery of the same area at two times, detect and segment changed pixels, then classify each change as **human-caused**, **natural**, or **uncertain**.

The location is currently a placeholder (`XYZ`). This starter accepts aligned raster files and does not download imagery until the area and time period are selected.

## Important scope distinction

Detecting that a pixel changed is not the same as proving why it changed. A new building is a strong candidate for human activity; a flood extent may be natural; vegetation loss can be caused by farming, fire, drought, or construction. The cause classifier must use labeled examples and supporting context, and it must be allowed to return `uncertain`.

## Starter workflow

1. Obtain cloud-masked, surface-reflectance images for before and after dates.
2. Make both images use the same projection, pixel grid, extent, and band order.
3. Run `src/change_detection.py` to create a binary GeoTIFF change mask.
4. Review the mask and correct false detections from clouds, shadows, seasonal changes, or misregistration.
5. Annotate changed regions with a cause label and evidence source.
6. Train and evaluate a cause classifier on location-separated examples.

The current code implements Step 3 as a simple baseline. It does not yet claim human/nature causes.

## Data plan

- **Sentinel-2 Level-2A:** candidate source for broad, repeated coverage. L2A provides surface reflectance and scene-classification information. Visible and near-infrared bands are 10 m; other bands have coarser resolution. This is appropriate for larger land-cover changes, not tiny objects.
- **Dynamic World:** optional land-cover context with nine classes and per-class probabilities at 10 m. A land-cover transition can support interpretation, but is not a label for the cause of a change.
- **LEVIR-CD:** research benchmark with bitemporal building-change image pairs and change annotations; useful for testing building-change segmentation, not for general natural-versus-human causation.
- **xBD / xView2:** pre- and post-disaster satellite imagery with building outlines and damage labels; useful for disaster-related damage examples, not a general label set for all natural changes.

Dataset domains differ in resolution, geography, sensor, and label definitions. Keep location- and dataset-separated evaluation to avoid learning dataset artifacts instead of cause.

## Evaluation

- Change segmentation: precision, recall, F1, and intersection-over-union (IoU).
- Cause classification: per-class precision/recall/F1, macro-F1, confusion matrix, and an uncertainty/abstention rate.
- Split by geographic area or event, not random neighboring pixels, so nearby imagery does not leak between training and test sets.

## Run the baseline

Create two co-registered GeoTIFFs with matching CRS, dimensions, transform, and band order. Use surface-reflectance values scaled to approximately 0-1 and mask clouds/shadows before running:

```text
python -m pip install -r requirements.txt
python src/change_detection.py --before data/before.tif --after data/after.tif --output outputs/change_mask.tif --threshold 0.08
```

The threshold is a starting value for experimentation, not a universal setting. Inspect outputs and tune it against labeled validation areas.

## Next milestones

1. Choose the XYZ area and comparison dates.
2. Acquire and align a small cloud-free image pair.
3. Review the binary mask and record false positives/negatives.
4. Define a cause-label guide and annotate examples with evidence.
5. Establish baselines and report performance by class and geography.
6. Train a segmentation/cause model only after enough reliable labels exist.

## References

- [Copernicus Sentinel-2 Level-2A product information](https://sentinels.copernicus.eu/web/sentinel/sentinel-data-access/sentinel-products/sentinel-2-data-products/collection-0-level-2a)
- [Dynamic World data catalog](https://developers.google.com/earth-engine/datasets/catalog/GOOGLE_DYNAMICWORLD_V1)
- [LEVIR-CD paper](https://levir.buaa.edu.cn/publications/remotesensing-798405-eng.pdf)
- [CMU SEI xView2 and xBD overview](https://www.sei.cmu.edu/projects/xview-2-challenge/)
