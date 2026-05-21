#include "separator_delegate.h"
#include <QPainter>

void SeparatorDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex&) const
{
    painter->fillRect(
        option.rect,
        QBrush(option.palette.color(QPalette::Accent), Qt::BDiagPattern)
    );
}

QSize SeparatorDelegate::sizeHint(const QStyleOptionViewItem&, const QModelIndex&) const
{
    return QSize();
}
