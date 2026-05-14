#include "film_editor.h"
#include "film_table_model.h"
#include "film_table_view.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>

FilmEditor::FilmEditor(QWidget* parent)
    : QWidget(parent)
{
    QHBoxLayout* actionBar = new QHBoxLayout;
    actionBar->addWidget(new QLineEdit);
    actionBar->addWidget(new QPushButton("+"));

    database::ConnectionParameters params = {"tcp:127.0.0.1", database::AuthenticationType::SqlPassword, "glaresheen", "CEaSa9b3Qa6HaYb9ba979aJ11VQI8a"};
    database::FilmTableModel* model = database::FilmTableModel::connect(params, this);
    FilmTableView* table = new FilmTableView(this);
    table->setModel(model);

    QVBoxLayout* screenLayout = new QVBoxLayout(this);
    screenLayout->addLayout(actionBar);
    screenLayout->addWidget(table);
}
