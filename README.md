# WinSelector

A lightweight, customizable alternative taskbar for Windows 11 built with Qt6. WinSelector displays all open windows as clickable tiles in a vertical panel on the right edge of your screen.

## Features

- **Clean, Modern Interface**: Frameless, translucent panel that blends with your desktop
- **Window Management**: View all open windows at a glance with icons and titles
- **Quick Window Switching**: Click any tile to bring that window to the foreground
- **Context Menu Actions**: Right-click to close windows directly from the panel
- **Smart Grouping**: Windows are automatically grouped by process name
- **Always on Top**: Panel stays visible above other windows for instant access
- **Auto-refresh**: Window list updates every 2 seconds to reflect system changes
- **Vertical Flow Layout**: Windows arranged vertically, wrapping to new columns as needed
- **Global Shortcut**: Toggle visibility instantly with the Home key

## Screenshots

![](./images/image.png)

## Requirements

### Runtime Requirements
- Windows 11 (or Windows 10)
- Microsoft Visual C++ 2015-2022 Redistributable (x64)

### Build Requirements
- CMake 3.16 or higher
- Ninja
- Qt6 (with Widgets module)
- MSVC 2022 or compatible C++17 compiler
- Windows SDK (for Win32 APIs)

## Building from Source

### 1. Install Qt6

Download and install Qt6 from [qt.io](https://www.qt.io/download). Make sure to install the MSVC 2022 64-bit component.

### 2. Set Environment Variable (Optional)

For easier development, set the `QT_SDK_DIR` environment variable:

```cmd
set QT_SDK_DIR=C:\path\to\Qt\6.x.x\msvc2022_64
```

### 3. Configure and Build

```cmd
cmake --preset Debug_Windows
cmake --build ./build/Debug_Windows
```

The executable will be located in `./build/Debug_Windows/WinSelector.exe`.

## Installation

### Method 1: Install with Qt Dependencies

```cmd
cmake --preset Release_Windows
cmake --build ./build/Release_Windows --target install
```

This will use `windeployqt` to automatically copy all required Qt DLLs to the installation directory.

### Method 2: Manual Deployment

1. Copy `./build/Release_Windows/output/bin/WinSelector.exe` to your desired location
2. Ensure Qt6 DLLs are in your system PATH, or copy them alongside the executable:
   - Qt6Core.dll
   - Qt6Gui.dll
   - Qt6Widgets.dll
   - icuuc.dll
   - And platform plugins (qwindows.dll in platforms/ folder)

## Usage

Simply run `WinSelector.exe`. The panel will appear on the right edge of your screen.

- **Home Key**: Toggle the visibility of the panel
- **Left-click** a window tile to activate and bring that window to the foreground
- **Right-click** a window tile to show the context menu and close the window
- The panel automatically updates to show new windows and remove closed ones

To exit the application, close it from the system taskbar or Task Manager.

## Architecture

### Core Components

- **MainWindow**: Root window container positioned at the right edge of the screen
- **WindowScanner**: Utility class that enumerates all visible windows using Win32 APIs
- **WindowTile**: Individual widget representing each open window with icon and title
- **FlowLayout**: Custom layout manager for vertical-wrapping tile arrangement

### Technologies Used

- **Qt6 Framework**: Cross-platform UI framework
- **Win32 API**: Native Windows APIs for window enumeration and management
  - EnumWindows, IsWindowVisible, GetWindowLongPtr
  - SetForegroundWindow, ShowWindow
  - Process Status API (Psapi) for process information

## Development

### Project Structure

```
WinSelector/
├── src/
│   ├── main.cpp              # Application entry point
│   ├── mainwindow.{h,cpp,ui} # Main window implementation
│   ├── windowscanner.{h,cpp} # Windows enumeration logic
│   ├── windowtile.{h,cpp}    # Window tile widget
│   ├── flowlayout.{h,cpp}    # Custom vertical-flow layout
│   ├── win32utils.{h,cpp}    # Win32 API utilities
│   └── config.h              # Configuration constants
├── resources/
│   ├── WinSelector_ja_JP.ts  # Japanese translation
│   ├── resources.qrc         # Qt resource file
│   └── WinSelector.rc        # Windows resource file
└── CMakeLists.txt            # Build configuration
```

### Internationalization

**W.I.P**

The project supports Japanese localization through Qt's translation system. To add more languages:

1. Create a new `.ts` file in `resources/`
2. Add it to `TS_FILES` in CMakeLists.txt
3. Run `lupdate` to extract translatable strings
4. Use Qt Linguist to translate

### Future Improvements

- **Performance**: Implement differential updates instead of recreating all tiles every refresh
- **Customization**: Add settings for panel position, width, and refresh interval
- **Filtering**: Add ability to filter or search windows
- **Multi-monitor**: Support for positioning on different monitors
- **Themes**: Customizable color schemes and transparency levels

## License

[MIT](LICENSE)

## Contributing

Contributions are welcome! Please feel free to submit issues or pull requests.

## Acknowledgments

- FlowLayout implementation inspired by Qt's flow layout example
- Built with the excellent Qt framework
