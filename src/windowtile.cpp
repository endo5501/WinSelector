#include "windowtile.h"
#include <QAction>
#include <QHBoxLayout>
#include <QMenu>

WindowTile::WindowTile(const WindowInfo &info, QWidget *parent)
    : QWidget(parent), m_info(info)
{
    setupUi();
    setupStyle();
    setCursor(Qt::PointingHandCursor);
    // Set a fixed height for consistency, width can be flexible or fixed
    setFixedHeight(TILE_HEIGHT);
    setFixedWidth(TILE_WIDTH); // Initial fixed width, can be adjusted
}

QSize WindowTile::sizeHint() const
{
    // Return the fixed size for proper layout calculations
    return QSize(TILE_WIDTH, TILE_HEIGHT);
}

void WindowTile::setInfo(const WindowInfo &info)
{
    m_info = info;

    if (!m_info.icon.isNull())
    {
        m_iconLabel->setPixmap(m_info.icon.pixmap(ICON_SIZE, ICON_SIZE));
    }
    else
    {
        m_iconLabel->setText("?");
    }

    // Calculate available width for title
    // Fixed width - margins(left+right) - spacing - icon
    int availableWidth = TILE_WIDTH - (CONTENT_MARGIN * 2) - INTERNAL_SPACING - ICON_SIZE;
    QFontMetrics metrics(m_titleLabel->font());
    QString elidedTitle = metrics.elidedText(m_info.title, Qt::ElideRight, availableWidth);
    m_titleLabel->setText(elidedTitle);
    m_titleLabel->setToolTip(m_info.title);
}

void WindowTile::setupUi()
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(CONTENT_MARGIN, CONTENT_MARGIN, CONTENT_MARGIN, CONTENT_MARGIN);
    layout->setSpacing(INTERNAL_SPACING);

    m_iconLabel = new QLabel(this);
    m_iconLabel->setFixedSize(ICON_SIZE, ICON_SIZE);
    m_iconLabel->setScaledContents(true);

    m_titleLabel = new QLabel(this);

    layout->addWidget(m_iconLabel);
    layout->addWidget(m_titleLabel);

    setInfo(m_info);
}

void WindowTile::setupStyle()
{
    // Basic styling
    setAttribute(Qt::WA_StyledBackground, true);
    
    QString bgColor = m_isActive ? "#E3F2FD" : "#FFFFFF"; // Light Blue for active
    QString borderColor = m_isActive ? "#2196F3" : "#ccc"; // Blue for active
    
    QString style = QString("WindowTile {"
                  "   background-color: %1;"
                  "   border: 1px solid %2;"
                  "   border-radius: 5px;"
                  "}"
                  "WindowTile:hover {"
                  "   background-color: #F0F0F0;"
                  "   border-color: #999;"
                  "}").arg(bgColor, borderColor);

    setStyleSheet(style);
}

void WindowTile::setActive(bool active)
{
    if (m_isActive != active)
    {
        m_isActive = active;
        setupStyle();
    }
}

void WindowTile::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit activated(m_info.hwnd);
    }
    else if (event->button() == Qt::RightButton)
    {
        QMenu contextMenu(this);
        QAction *closeAction =
            contextMenu.addAction("ウィンドウを閉じる"); // "Close Window"
        connect(closeAction, &QAction::triggered, this,
                [this]()
                { emit closed(m_info.hwnd); });
        contextMenu.exec(event->globalPosition().toPoint());
    }
}
