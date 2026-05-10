#include "image_path_delegate.h"
#include <QPainter>

void ImagePathDelegate::paint(QPainter* painter, const QStyleOptionViewItem& style, const QModelIndex& index) const
{
    painter->save();
    QStyleOptionViewItem option = style;
    initStyleOption(&option, index);

    painter->drawPixmap(option.rect, QPixmap(index.data().toString()));

    painter->restore();
}
