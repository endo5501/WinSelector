## 1. Geometry alignment

- [x] 1.1 Trace the panel sizing path and make width estimation use the same effective layout area that tile placement uses.
- [x] 1.2 Update `FlowLayout` wrap calculations to use boundary-safe height checks for exact-fit and overflow cases.

## 2. Panel layout integration

- [x] 2.1 Adjust the main window/container structure as needed so hidden top-level geometry offsets do not cause under-sized multi-column panels.
- [x] 2.2 Verify that refreshed and reused tiles remain visible and correctly ordered after the layout sizing changes.

## 3. Regression validation

- [x] 3.1 Validate tile visibility with window counts around the two-column and three-column wrap thresholds.
- [x] 3.2 Confirm that tile activation, closing, and normal refresh behavior remain unchanged after the multi-column fix.
