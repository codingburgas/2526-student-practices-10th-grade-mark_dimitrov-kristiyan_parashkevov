#pragma once

#include <QObject>

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
    void revertUnsaved();

private:
    SeparatorDelegate* separator = nullptr;
    void deleteSeparator();

    QTableView* view;
    FilmTableModel* model;
};
