#include "film_editor.h"
#include "film_table_model.h"
#include "film_table_view.h"
#include "database_connection_dialog.h"
#include "db_connection_parameters.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
using namespace Qt::StringLiterals;

FilmEditor::FilmEditor(QWidget* parent)
    : QWidget(parent)
    , connectionDialog(new DatabaseConnectionDialog(this))
{
    QIcon rowAddIcon = QIcon::fromTheme(QIcon::ThemeIcon::ListAdd);
    QIcon saveIcon = QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave);
    QIcon revertIcon = QIcon::fromTheme(QIcon::ThemeIcon::EditUndo);

    QPushButton* rowAddButton = new QPushButton(rowAddIcon, rowAddIcon.isNull() ? u"New"_s : QString());
    QPushButton* saveButton = new QPushButton(saveIcon, saveIcon.isNull() ? u"Save"_s : QString());
    QPushButton* revertButton = new QPushButton(revertIcon, revertIcon.isNull() ? u"Revert"_s : QString());
    QHBoxLayout* actionBar = new QHBoxLayout;
    actionBar->addWidget(new QLineEdit);
    actionBar->addWidget(rowAddButton);
    actionBar->addWidget(saveButton);
    actionBar->addWidget(revertButton);

    connectionDialog->open();
    QObject::connect(connectionDialog, &QDialog::accepted, this, &FilmEditor::connect);

    QVBoxLayout* screenLayout = new QVBoxLayout(this);
    screenLayout->addLayout(actionBar);
    table = new FilmTableView(screenLayout);

    QObject::connect(rowAddButton, &QPushButton::clicked, table, &FilmTableView::insertRow);
    QObject::connect(saveButton, &QPushButton::clicked, table, &FilmTableView::save);
    QObject::connect(revertButton, &QPushButton::clicked, table, &FilmTableView::revertUnsaved);
}

void FilmEditor::connect()
{
    database::ConnectionParameters connectionParameters = connectionDialog->createConnectionParameters();
    table->setModel(FilmTableModel::connect(connectionParameters));
}
