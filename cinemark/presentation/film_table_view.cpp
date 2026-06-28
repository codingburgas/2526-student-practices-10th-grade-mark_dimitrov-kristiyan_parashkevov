#include "film_table_view.h"
#include "film_table_model.h"
#include "image_path_delegate.h"
#include "separator_delegate.h"
#include <QMenu>
#include <QLayout>
#include <QTableView>
#include <QHeaderView>

FilmTableView::FilmTableView(QLayout* layout, FilmTableModel* model)
    : QObject(layout)
    , view(new QTableView)
    , model(model)
{
    view->setModel(model);
    view->verticalHeader()->setDefaultSectionSize(150);
    view->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(view, &QTableView::customContextMenuRequested, this, &FilmTableView::createContextMenu);

    QAction* deleteAction = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete), "Delete Film", view);
    view->addAction(deleteAction);

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
        view->resizeRowToContents(1);
    }
    else
    {
        view->setItemDelegateForRow(separatorRow, nullptr);
        view->verticalHeader()->resizeSection(separatorRow, 150);
        model->insertRow();
        view->setItemDelegateForRow(model->separatorRow(), separator);
        view->resizeRowToContents(model->separatorRow());
    }
}

void FilmTableView::createContextMenu(const QPoint& location)
{
    QPoint globalLocation = view->mapToGlobal(location);

    QMenu menu(view);
    menu.addActions(view->actions());
    QAction* action = menu.exec(globalLocation);

    if (action && action->text() == "Delete Film")
    {
        deleteRow(view->rowAt(globalLocation.y()));
    }
}

void FilmTableView::deleteRow(int row)
{
    if (!model)
        return;

    model->deleteRow(row);
}

void FilmTableView::save()
{
    deleteSeparator();
    model->submitAll();
    model->select();
}

void FilmTableView::revertUnsaved()
{
    deleteSeparator();
    model->revertAll();
}

void FilmTableView::deleteSeparator()
{
    int separatorRow = model->separatorRow();
    if (separatorRow != -1)
    {
        view->setItemDelegateForRow(separatorRow, nullptr);
        view->verticalHeader()->resizeSection(separatorRow, 150);
        separator->deleteLater();
        separator = nullptr;
    }
}

void FilmTableView::setModel(FilmTableModel* model)
{
    view->setModel(model);
    this->model = model;

    view->hideColumn(0);
    view->setItemDelegateForColumn(1, new ImagePathDelegate(view));
}
