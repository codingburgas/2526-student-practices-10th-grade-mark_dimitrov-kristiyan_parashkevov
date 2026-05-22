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
    view->setAlternatingRowColors(true);
    view->setItemDelegateForColumn(0, new ImagePathDelegate(view));

    layout->addWidget(view);
}

void FilmTableView::insertRow()
{
    if (!model)
        return;

    if (!newRowsSeparatorIndex.isValid())
    {
        model->insertRows(0, 2);
        newRowsSeparatorIndex = model->index(1, 0);
        separator = new SeparatorDelegate(this);
        view->setItemDelegateForRow(1, separator);
    }
    else
    {
        view->setItemDelegateForRow(newRowsSeparatorIndex.row(), nullptr);
        model->insertRow(0);
        view->setItemDelegateForRow(newRowsSeparatorIndex.row(), separator);
    }
}

void FilmTableView::save()
{
    // if dirty after save then don't remove separator?
    // is it dirty when there are empty unsubmitted rows?
}

void FilmTableView::setModel(FilmTableModel* model)
{
    view->setModel(model);
    this->model = model;
}
