## Context

WinSelector rebuilds the tile layout on each refresh and resizes the panel width based on `FlowLayout::totalWidthForHeight()`. The current implementation estimates required width from the outer main window height, then performs actual placement inside the central widget area. Because the application uses `QMainWindow` semantics and a custom flow layout, the geometry used for width estimation can differ from the geometry available during real placement. Near a column boundary, that mismatch can under-estimate the number of columns required and push the final column outside the visible panel.

The issue is rare because it only appears when the tile count sits near the exact wrap threshold for the available height. Even a small difference between the estimated and actual layout height is enough to move the last tile into an additional column.

## Goals / Non-Goals

**Goals:**
- Ensure width estimation and real tile placement use equivalent geometry constraints.
- Ensure wrapped multi-column layouts keep every tile visible within the panel bounds.
- Remove boundary-condition errors in column wrapping when the final tile exactly fits the remaining height.
- Keep existing tile ordering, refresh cadence, and interactions unchanged.

**Non-Goals:**
- Redesigning the visual appearance of the panel or tiles.
- Changing window enumeration, sorting, or icon refresh behavior.
- Replacing the custom flow layout with a different layout system unless needed for correctness.

## Decisions

### Use a single source of truth for layout geometry

The panel width calculation and the actual tile placement SHALL be driven by the same effective layout area. The implementation should derive a layout rectangle from the widget that actually owns the `FlowLayout`, and reuse equivalent dimensions when estimating required width and when applying geometry.

Rationale:
- The current bug stems from measuring with one height and laying out with another.
- Aligning both calculations removes the most likely cause of hidden last columns without altering tile ordering logic.

Alternatives considered:
- Add a safety margin to the computed width. Rejected because it hides the symptom instead of fixing the mismatch.
- Leave the current estimation in place and only tweak wrap thresholds. Rejected because geometry mismatch would still exist.

### Make column wrap calculations boundary-safe

`FlowLayout` should use a consistent half-open style boundary check when deciding whether a tile still fits in the current column. The wrap decision should be based on the effective top plus available height, not on `QRect::bottom()` inclusive semantics.

Rationale:
- Inclusive bottom-edge comparisons are error-prone around exact-fit conditions.
- A consistent height-based check is easier to reason about and test.

Alternatives considered:
- Keep the current boundary check and add special cases. Rejected because it preserves ambiguous geometry semantics.

### Simplify the top-level container if needed to eliminate hidden geometry offsets

If geometry remains inconsistent because of `QMainWindow` internals such as central widget offsets or unused menu/status regions, the top-level window should be simplified so the layout host widget more directly matches the visible panel.

Rationale:
- The app does not rely on `QMainWindow` features beyond hosting the content.
- Removing unused top-level layout indirection is a straightforward way to reduce hidden geometry differences.

Alternatives considered:
- Keep `QMainWindow` unchanged and compensate manually for every offset. Accepted only as a fallback if a simpler container-level fix is sufficient and lower risk.

## Risks / Trade-offs

- [Geometry assumptions differ across DPI or style configurations] -> Verify calculations against the actual layout host rect, not a hard-coded offset.
- [Changing top-level window structure could affect tray or hotkey behavior] -> Preserve existing signals, native event handling, and window flags during refactor.
- [Boundary-fix changes could alter the exact column break point] -> Validate behavior with tile counts around wrap thresholds and ensure all tiles remain visible.
- [Layout code remains custom and non-trivial] -> Keep the fix narrowly scoped and document the geometry invariants in the code.

## Migration Plan

No data migration is required. The change can ship as a normal application update. If the top-level widget structure is simplified, preserve current window flags and startup behavior so deployment remains transparent to users.

Rollback is straightforward: revert the layout sizing changes if regressions appear in panel sizing or tile interaction.

## Open Questions

- Can the issue be resolved entirely by aligning geometry calculations, or is removing unused `QMainWindow` chrome also necessary?
- Should the final implementation add a focused regression test or diagnostic harness for wrap-boundary cases, given the current project structure?
