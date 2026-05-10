#include "film_table_view.h"
#include "image_path_delegate.h"

FilmTableView::FilmTableView(QWidget* parent)
    : QTableView(parent)
{
    setItemDelegateForColumn(0, new ImagePathDelegate(this));
}
