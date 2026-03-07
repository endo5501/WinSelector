# multi-column-tile-layout Specification

## Purpose
TBD - created by archiving change fix-missing-tiles-in-multi-column-layout. Update Purpose after archive.
## Requirements
### Requirement: Multi-column tile layouts keep all tiles visible
When the panel wraps tiles into multiple columns, the system SHALL keep every enumerated tile visible within the panel's content area.

#### Scenario: Third column is required
- **WHEN** the number of tiles exceeds the vertical capacity of two columns
- **THEN** the panel width MUST expand to include a visible third column
- **AND** the tiles assigned to the third column MUST remain visible and reachable

#### Scenario: Layout refresh occurs near a wrap boundary
- **WHEN** the tile count is near the threshold where one additional tile creates a new column
- **THEN** the panel MUST size itself using the same effective layout constraints that are used to place tiles
- **AND** no tile may be positioned outside the visible panel because of an underestimated width

### Requirement: Column wrap decisions are stable at height boundaries
The system SHALL determine column wrapping with boundary-safe height calculations so a tile that fits within the available height is not incorrectly forced into a hidden extra column.

#### Scenario: Final tile exactly fits the remaining height
- **WHEN** the remaining vertical space in the current column is exactly sufficient for the next tile
- **THEN** the tile MUST remain in the current column

#### Scenario: Final tile exceeds the remaining height
- **WHEN** adding the next tile would exceed the available vertical space in the current column
- **THEN** the tile MUST wrap to the next visible column

### Requirement: Multi-column correction preserves existing tile semantics
The fix for multi-column visibility SHALL preserve existing tile enumeration, sort order, and interactions.

#### Scenario: Layout correction during normal refresh
- **WHEN** the panel refreshes after windows are opened, closed, or reordered
- **THEN** all currently enumerated windows MUST still appear in the existing sort order
- **AND** tile activation and close interactions MUST continue to behave as before

