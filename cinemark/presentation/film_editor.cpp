#include "film_editor.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTableView>

#include "testtablemodel.h"

FilmEditor::FilmEditor(QWidget* parent)
    : QWidget(parent)
{
    QHBoxLayout* actionBar = new QHBoxLayout;
    actionBar->addWidget(new QLineEdit);
    actionBar->addWidget(new QPushButton("+"));

    QTableView* table = new QTableView(this);
    SimpleTableModel* model = new SimpleTableModel(this);
    table->setModel(model);

    QVBoxLayout* screenLayout = new QVBoxLayout(this);
    screenLayout->addLayout(actionBar);
    screenLayout->addWidget(table);
}
