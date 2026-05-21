#pragma once

#include <QObject>
#include <QPersistentModelIndex>

class QLayout;
class QTableView;
class FilmTableModel;
class SeparatorDelegate;

class FilmTableView : public QObject
{
    Q_OBJECT

public:
    explicit FilmTableView(QLayout* parent, FilmTableModel* = nullptr);

    void setModel(FilmTableModel*);

public slots:
    void insertRow();
    void save();

private:
    QPersistentModelIndex newRowsSeparatorIndex;
    SeparatorDelegate* separator = nullptr;

    QTableView* view;
    FilmTableModel* model;
};
