#include "flowlayout.h"
#include <QDebug>
#include <QWidget>

FlowLayout::FlowLayout(QWidget *parent, int margin, int hSpacing, int vSpacing)
    : QLayout(parent), m_hSpace(hSpacing), m_vSpace(vSpacing)
{
    setContentsMargins(margin, margin, margin, margin);
}

FlowLayout::FlowLayout(int margin, int hSpacing, int vSpacing)
    : m_hSpace(hSpacing), m_vSpace(vSpacing)
{
    setContentsMargins(margin, margin, margin, margin);
}

FlowLayout::~FlowLayout()
{
    QLayoutItem *item;
    while ((item = takeAt(0)))
    {
        delete item;
    }
}

void FlowLayout::addItem(QLayoutItem *item)
{
    m_itemList.append(item);
    invalidate();
}

int FlowLayout::totalWidthForHeight(int height) const
{
    // Use a dummy rect with very large width and specified height
    // This ensures all items can fit horizontally and only wrap vertically when needed
    // For RTL mode, we need a valid positive width for correct calculations
    return doLayout(QRect(0, 0, 10000, height), true);
}

int FlowLayout::horizontalSpacing() const
{
    if (m_hSpace >= 0)
    {
        return m_hSpace;
    }
    return smartSpacing(QStyle::PM_LayoutHorizontalSpacing);
}

int FlowLayout::verticalSpacing() const
{
    if (m_vSpace >= 0)
    {
        return m_vSpace;
    }
    return smartSpacing(QStyle::PM_LayoutVerticalSpacing);
}

int FlowLayout::count() const
{
    return m_itemList.size();
}

QLayoutItem *FlowLayout::itemAt(int index) const
{
    return m_itemList.value(index);
}

QLayoutItem *FlowLayout::takeAt(int index)
{
    if (index >= 0 && index < m_itemList.size())
    {
        QLayoutItem *item = m_itemList.takeAt(index);
        invalidate();
        return item;
    }
    return nullptr;
}

Qt::Orientations FlowLayout::expandingDirections() const
{
    return {};
}

bool FlowLayout::hasHeightForWidth() const
{
    return false;
}

int FlowLayout::heightForWidth(int width) const
{
    return -1;
}

void FlowLayout::setGeometry(const QRect &rect)
{
    QLayout::setGeometry(rect);
    doLayout(rect, false);
}

QSize FlowLayout::sizeHint() const
{
    return minimumSize();
}

QSize FlowLayout::minimumSize() const
{
    QSize size;
    for (const QLayoutItem *item : m_itemList)
    {
        size = size.expandedTo(item->minimumSize());
    }

    const QMargins margins = contentsMargins();
    size += QSize(margins.left() + margins.right(), margins.top() + margins.bottom());
    return size;
}

int FlowLayout::doLayout(const QRect &rect, bool testOnly) const
{
    int left, top, right, bottom;
    getContentsMargins(&left, &top, &right, &bottom);
    QRect effectiveRect = rect.adjusted(+left, +top, -right, -bottom);
    int x = m_isRTL ? effectiveRect.right() + 1 : effectiveRect.x();
    int y = effectiveRect.y();

    int columnWidth = 0;
    int maxColumnHeight = 0;

    int index = 0;
    for (QLayoutItem *item : m_itemList)
    {
        QSize size;

        // When testOnly=true (calculating width), use widget's sizeHint directly
        // because QWidgetItem::sizeHint() returns (0,0) for hidden widgets
        if (testOnly && item->widget())
        {
            size = item->widget()->sizeHint();
        }
        else
        {
            size = item->sizeHint();
        }

        // If we are not at the top, and adding this item would exceed bottom...
        bool wrap = false;
        if (effectiveRect.height() > 0 &&
            y + size.height() > effectiveRect.bottom() && y > effectiveRect.y())
        {
            wrap = true;
        }

        if (wrap)
        {
            if (m_isRTL)
            {
                x -= columnWidth + horizontalSpacing();
            }
            else
            {
                x += columnWidth + horizontalSpacing();
            }
            y = effectiveRect.y();
            columnWidth = 0;
        }

        if (!testOnly)
        {
            if (m_isRTL)
            {
                // Align right
                item->setGeometry(QRect(QPoint(x - size.width(), y), size));
            }
            else
            {
                item->setGeometry(QRect(QPoint(x, y), size));
            }
        }

        columnWidth = qMax(columnWidth, size.width());
        y += size.height() + verticalSpacing();
        maxColumnHeight = qMax(maxColumnHeight, y - effectiveRect.y());
        index++;
    }

    // Return the total width used
    // Note: this return value is often used for sizeHint, but sizeHint usually
    // calls with unconstrained rect? If rect is unconstrained (height large), we
    // get 1 column.
    if (m_isRTL)
    {
        return (effectiveRect.right() + 1) - (x - columnWidth) + right + left;
    }
    else
    {
        return x + columnWidth + right + left - rect.x();
    }
}

int FlowLayout::smartSpacing(QStyle::PixelMetric pm) const
{
    QObject *parent = this->parent();
    if (!parent)
    {
        return -1;
    }
    else if (parent->isWidgetType())
    {
        QWidget *pw = static_cast<QWidget *>(parent);
        return pw->style()->pixelMetric(pm, nullptr, pw);
    }
    else
    {
        return static_cast<QLayout *>(parent)->spacing();
    }
}
