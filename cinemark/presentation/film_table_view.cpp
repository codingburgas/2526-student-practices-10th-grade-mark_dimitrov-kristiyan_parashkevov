#include "film_table_view.h"
#include "film_table_model.h"
#include "image_path_delegate.h"
#include "separator_delegate.h"
#include <QLayout>
#include <QTableView>
#include <QPersistentModelIndex>

FilmTableView::FilmTableView(QLayout* layout, FilmTableModel* model)
    : QObject(layout)
    , view(new QTableView)
    , model(model)
{
    view->setModel(model);
    view->setItemDelegateForColumn(0, new ImagePathDelegate(view));

    layout->addWidget(view);
}

void FilmTableView::insertRow()
{
    if (!model)
        return;

    int separatorRow = model->separatorRow();
    if (separatorRow == -1)
    {
        model->insertRow();
        separator = new SeparatorDelegate(this);
        view->setItemDelegateForRow(1, separator);
    }
    else
    {
        view->setItemDelegateForRow(separatorRow, nullptr);
        model->insertRow();
        view->setItemDelegateForRow(model->separatorRow(), separator);
    }
}

void FilmTableView::save()
{
    int separatorRow = model->separatorRow();
    if (separatorRow != -1)
    {
        view->setItemDelegateForRow(separatorRow, nullptr);
        separator->deleteLater(); separator = nullptr;
    }

    model->submitAll();
    model->select();
}

void FilmTableView::setModel(FilmTableModel* model)
{
    view->setModel(model);
    this->model = model;
}
