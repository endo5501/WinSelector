## Why

When the number of window tiles grows enough to wrap into multiple columns, WinSelector can rarely fail to show the tiles that should appear in the last column. This breaks the core promise of the app because some open windows become unreachable from the panel, and the issue is hard to predict once the layout reaches a column boundary.

## What Changes

- Define expected behavior for multi-column tile layout so all enumerated windows remain visible when the panel wraps into additional columns.
- Align panel width calculation with the actual layout area used to place tiles, so required columns are measured with the same geometry constraints used for rendering.
- Tighten column wrap behavior at height boundaries to avoid off-by-one placement that can push the final column outside the visible panel.
- Preserve existing refresh behavior, tile ordering, and interaction semantics while eliminating last-column omission.

## Capabilities

### New Capabilities
- `multi-column-tile-layout`: Defines visibility and sizing requirements for wrapped tile columns so every window tile remains accessible when the panel expands beyond one column.

### Modified Capabilities

## Impact

- Affected code: `src/mainwindow.cpp`, `src/mainwindow.h`, `src/flowlayout.cpp`, `src/flowlayout.h`, and potentially `src/mainwindow.ui`
- Affected behavior: panel sizing, multi-column tile placement, and layout boundary handling
- No external API or dependency changes are expected
