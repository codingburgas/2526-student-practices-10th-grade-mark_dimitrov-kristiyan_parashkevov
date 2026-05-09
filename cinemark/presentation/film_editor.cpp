#include "film_editor.h"
#include "film_table_model.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTableView>

FilmEditor::FilmEditor(QWidget* parent)
    : QWidget(parent)
{
    QHBoxLayout* actionBar = new QHBoxLayout;
    actionBar->addWidget(new QLineEdit);
    actionBar->addWidget(new QPushButton("+"));

    dbConnectionParameters params = {"tcp:127.0.0.1", "glaresheen", "WZ2a765bbcM95Fb7cccJOb38BJU2Ea"};
    FilmTableModel* model = FilmTableModel::connect(params, this);
    QTableView* table = new QTableView(this);
    table->setModel(model);

    QVBoxLayout* screenLayout = new QVBoxLayout(this);
    screenLayout->addLayout(actionBar);
    screenLayout->addWidget(table);
}
