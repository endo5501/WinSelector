# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

WinSelector is a Windows-only Qt6 application that serves as an alternative taskbar for Windows 11. It displays a panel on the right edge of the screen showing all open windows as clickable tiles with icons and titles.

**Primary Language:** C++ with Qt6 framework
**Target Platform:** Windows (uses Win32 API extensively)

## Build System

This project uses CMake with Qt6.

### Building the Application

```bash
cmake -B build -S .
cmake --build build
```

The executable will be located in the build directory.

### Running the Application

The application requires Qt6 DLLs to be in the system PATH. The launch.json configuration expects `QT_SDK_DIR` environment variable to be set:

```bash
set QT_SDK_DIR=C:\path\to\Qt\6.x.x\msvc2022_64
.\build\WinSelector.exe
```

## Architecture

### Core Components

1. **MainWindow** (`mainwindow.h/cpp`)
   - Root window positioned on the right edge of the screen
   - Frameless, always-on-top overlay with translucent background
   - Contains a FlowLayout that arranges WindowTiles
   - Refreshes window list every 2 seconds via QTimer

2. **WindowScanner** (`src/windowscanner.h/cpp`)
   - Static utility class that scans all visible windows using Win32 EnumWindows API
   - Extracts window title, icon, process name, and HWND for each window
   - Filters out invisible windows, tool windows, and special windows like "Program Manager"
   - Uses Psapi.h to retrieve process information

3. **WindowTile** (`src/windowtile.h/cpp`)
   - Individual widget representing one window
   - Displays icon (32x32) + title text
   - Left-click activates the window (brings to foreground)
   - Right-click shows context menu to close the window

4. **FlowLayout** (`src/flowlayout.h/cpp`)
   - Custom QLayout that arranges tiles vertically, wrapping to new columns when screen height is exhausted
   - Based on Qt's flow layout example but modified for vertical-first flow

### Data Flow

1. Timer fires every 2 seconds → `MainWindow::refreshWindows()`
2. Calls `WindowScanner::getWindows()` to enumerate all windows
3. Sorts windows by process name (grouping same applications together)
4. Recreates all WindowTile widgets and adds them to FlowLayout
5. User clicks tile → emits signal → MainWindow calls Win32 API to activate/close window

### Windows API Integration

The application uses several Win32 APIs:
- `EnumWindows` - enumerate all top-level windows
- `IsWindowVisible`, `GetWindowLongPtr` - filter windows
- `GetWindowText`, `SendMessage(WM_GETICON)` - extract window info
- `OpenProcess`, `EnumProcessModules`, `GetModuleBaseName` - get process names
- `SetForegroundWindow`, `ShowWindow` - activate windows
- `PostMessage(WM_CLOSE)` - close windows

## Important Implementation Notes

### Performance Consideration

The current implementation recreates all WindowTile widgets every 2 seconds (see `mainwindow.cpp:42`). This is simple but inefficient. For optimization, consider comparing the window list and only updating changes.

### Localization

The project supports Japanese localization via Qt's translation system (`WinSelector_ja_JP.ts`). The UI text in `windowtile.cpp:56` uses Japanese text "ウィンドウを閉じる" (Close Window).

### Window Positioning

The main window is positioned at the right edge of the primary screen with a fixed width of 300px and full screen height (`mainwindow.cpp:38`). The window uses `Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool` flags.

## Development Dependencies

Required libraries (linked in CMakeLists.txt):
- Qt6::Widgets
- user32.lib (Win32 window management)
- gdi32.lib (GDI graphics)
- psapi.lib (Process status API)

## File Structure

- `main.cpp` - Application entry point with translation setup
- `mainwindow.{h,cpp,ui}` - Main window implementation
- `src/windowscanner.{h,cpp}` - Windows enumeration logic
- `src/windowtile.{h,cpp}` - Individual window tile widget
- `src/flowlayout.{h,cpp}` - Custom layout for vertical-wrapping arrangement
- `CMakeLists.txt` - Build configuration
