#pragma once

#include "db_connection_parameters.h"
#include <QHash>
#include <QSqlTableModel>

class FilmTableModel : public QSqlTableModel
{
    Q_OBJECT

public:
    static FilmTableModel* connect(const database::ConnectionParameters&, QObject* parent = nullptr);

    int separatorRow() const;

    bool insertRows(int count = 1, int row = 0, const QModelIndex& parent = QModelIndex()) override;
    bool insertRow() { return insertRows(); }
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    QVariant headerData(int row, Qt::Orientation, int = Qt::DisplayRole) const override;

public slots:
    bool submitAll();
    void revertAll();

private:
    FilmTableModel(QObject* parent = nullptr);
    static bool ensureFilmsTable();

    QPersistentModelIndex insertedRowsSeparatorIndex;
    QHash<QPersistentModelIndex, QHash<int, QHashDummyValue>> changedRows;
    void clearChangeMarkers();
};
