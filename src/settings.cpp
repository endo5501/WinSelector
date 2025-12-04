#include "settings.h"
#include <QKeySequence>
#include <windows.h>

Settings& Settings::instance()
{
    static Settings s;
    return s;
}

Settings::Settings()
{
    m_settings = new QSettings("Settings.ini", QSettings::IniFormat);
    
    // Write defaults if missing so the user has a template
    if (!m_settings->contains("MainWindow/RefreshIntervalMs")) m_settings->setValue("MainWindow/RefreshIntervalMs", 2000);
    if (!m_settings->contains("MainWindow/CloseRefreshDelayMs")) m_settings->setValue("MainWindow/CloseRefreshDelayMs", 500);
    if (!m_settings->contains("MainWindow/InitialWidth")) m_settings->setValue("MainWindow/InitialWidth", 300);
    if (!m_settings->contains("MainWindow/MinimumWidth")) m_settings->setValue("MainWindow/MinimumWidth", 300);

    if (!m_settings->contains("Layout/Margin")) m_settings->setValue("Layout/Margin", 2);
    if (!m_settings->contains("Layout/HSpacing")) m_settings->setValue("Layout/HSpacing", 2);
    if (!m_settings->contains("Layout/VSpacing")) m_settings->setValue("Layout/VSpacing", 2);

    if (!m_settings->contains("WindowScanner/MaxTitleLength")) m_settings->setValue("WindowScanner/MaxTitleLength", 256);

    if (!m_settings->contains("WindowTile/Width")) m_settings->setValue("WindowTile/Width", 250);
    if (!m_settings->contains("WindowTile/Height")) m_settings->setValue("WindowTile/Height", 30);
    if (!m_settings->contains("WindowTile/IconSize")) m_settings->setValue("WindowTile/IconSize", 16);
    if (!m_settings->contains("WindowTile/ContentMargin")) m_settings->setValue("WindowTile/ContentMargin", 2);
    if (!m_settings->contains("WindowTile/InternalSpacing")) m_settings->setValue("WindowTile/InternalSpacing", 5);
    if (!m_settings->contains("WindowTile/EnableShiftClickClose")) m_settings->setValue("WindowTile/EnableShiftClickClose", false);

    if (!m_settings->contains("Display/TargetDisplayIndex")) m_settings->setValue("Display/TargetDisplayIndex", 0);

    if (!m_settings->contains("Shortcuts/ToggleVisibility")) m_settings->setValue("Shortcuts/ToggleVisibility", "Home");

    m_settings->sync();
    load();
}

void Settings::load()
{
    // MainWindow
    mainWindowRefreshIntervalMs = m_settings->value("MainWindow/RefreshIntervalMs", 2000).toInt();
    mainWindowCloseRefreshDelayMs = m_settings->value("MainWindow/CloseRefreshDelayMs", 500).toInt();
    mainWindowInitialWidth = m_settings->value("MainWindow/InitialWidth", 300).toInt();
    mainWindowMinimumWidth = m_settings->value("MainWindow/MinimumWidth", 300).toInt();

    // Layout
    layoutMargin = m_settings->value("Layout/Margin", 2).toInt();
    layoutHSpacing = m_settings->value("Layout/HSpacing", 2).toInt();
    layoutVSpacing = m_settings->value("Layout/VSpacing", 2).toInt();

    // WindowScanner
    windowScannerMaxTitleLength = m_settings->value("WindowScanner/MaxTitleLength", 256).toInt();

    // WindowTile
    tileWidth = m_settings->value("WindowTile/Width", 250).toInt();
    tileHeight = m_settings->value("WindowTile/Height", 30).toInt();
    tileIconSize = m_settings->value("WindowTile/IconSize", 16).toInt();
    tileContentMargin = m_settings->value("WindowTile/ContentMargin", 2).toInt();
    tileInternalSpacing = m_settings->value("WindowTile/InternalSpacing", 5).toInt();
    tileEnableShiftClickClose = m_settings->value("WindowTile/EnableShiftClickClose", false).toBool();

    // Display
    targetDisplayIndex = m_settings->value("Display/TargetDisplayIndex", 0).toInt();

    // Shortcuts
    toggleVisibilityShortcut = m_settings->value("Shortcuts/ToggleVisibility", "Home").toString();
}

int Settings::getToggleVisibilityKeyVk()
{
    QKeySequence seq(toggleVisibilityShortcut);
    if (seq.isEmpty()) return VK_HOME;

    int k = seq[0].key();
    // Remove modifiers to get the pure key code
    // Qt::Key is the lower part, modifiers are high bits
    // But seq[0] is an int (combination).
    // The key() method of QKeyCombination (Qt6) or just casting in Qt5.
    // Assuming Qt6 or Qt5, let's be safe.
    
    // In Qt5/6, int value contains modifiers.
    // We want to extract the Qt::Key part.
    // Qt::Key is 32-bit, but usually masked.
    // Actually, let's just use the qtKeyToVk with the masked value.
    
    // Note: QKeySequence[0] returns an int (or QKeyCombination in Qt6).
    // We can cast to int.
    int combined = seq[0];
    int key = combined & ~Qt::KeyboardModifierMask;
    
    return qtKeyToVk((Qt::Key)key);
}

int Settings::qtKeyToVk(Qt::Key key)
{
    if (key >= Qt::Key_A && key <= Qt::Key_Z)
        return 'A' + (key - Qt::Key_A);
    if (key >= Qt::Key_0 && key <= Qt::Key_9)
        return '0' + (key - Qt::Key_0);
    
    switch (key) {
        case Qt::Key_Home: return VK_HOME;
        case Qt::Key_End: return VK_END;
        case Qt::Key_Left: return VK_LEFT;
        case Qt::Key_Up: return VK_UP;
        case Qt::Key_Right: return VK_RIGHT;
        case Qt::Key_Down: return VK_DOWN;
        case Qt::Key_PageUp: return VK_PRIOR;
        case Qt::Key_PageDown: return VK_NEXT;
        case Qt::Key_Insert: return VK_INSERT;
        case Qt::Key_Delete: return VK_DELETE;
        case Qt::Key_Space: return VK_SPACE;
        case Qt::Key_Backspace: return VK_BACK;
        case Qt::Key_Return: return VK_RETURN;
        case Qt::Key_Enter: return VK_RETURN;
        case Qt::Key_Escape: return VK_ESCAPE;
        case Qt::Key_Tab: return VK_TAB;
        
        case Qt::Key_F1: return VK_F1;
        case Qt::Key_F2: return VK_F2;
        case Qt::Key_F3: return VK_F3;
        case Qt::Key_F4: return VK_F4;
        case Qt::Key_F5: return VK_F5;
        case Qt::Key_F6: return VK_F6;
        case Qt::Key_F7: return VK_F7;
        case Qt::Key_F8: return VK_F8;
        case Qt::Key_F9: return VK_F9;
        case Qt::Key_F10: return VK_F10;
        case Qt::Key_F11: return VK_F11;
        case Qt::Key_F12: return VK_F12;
        
        default: return VK_HOME;
    }
}
