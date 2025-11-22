#ifndef WINDOWTILE_H
#define WINDOWTILE_H

#include "windowscanner.h"
#include <QLabel>
#include <QMouseEvent>
#include <QWidget>

class WindowTile : public QWidget
{
    Q_OBJECT
public:
    explicit WindowTile(const WindowInfo &info, QWidget *parent = nullptr);
    WindowInfo getInfo() const { return m_info; }
    void setInfo(const WindowInfo &info);
    void setActive(bool active);

    QSize sizeHint() const override;

    // Configuration Constants
    static constexpr int TILE_WIDTH = 250;
    static constexpr int TILE_HEIGHT = 30;
    static constexpr int ICON_SIZE = 16;       // Reduced from 32
    static constexpr int CONTENT_MARGIN = 2;   // Reduced from 5
    static constexpr int INTERNAL_SPACING = 5; // Reduced from 10

signals:
    void activated(HWND hwnd);
    void closed(HWND hwnd);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    WindowInfo m_info;
    bool m_isActive = false;
    QLabel *m_iconLabel;
    QLabel *m_titleLabel;

    void setupUi();
    void setupStyle();
};

#endif // WINDOWTILE_H
