#include "film_editor.h"
#include "film_table_model.h"
#include "film_table_view.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
using namespace Qt::StringLiterals;

FilmEditor::FilmEditor(QWidget* parent)
    : QWidget(parent)
{
    QIcon rowAddIcon = QIcon::fromTheme(QIcon::ThemeIcon::ListAdd);

    QPushButton* rowAddButton = new QPushButton(rowAddIcon, rowAddIcon.isNull() ? u"New"_s : QString());
    QHBoxLayout* actionBar = new QHBoxLayout;
    actionBar->addWidget(new QLineEdit);
    actionBar->addWidget(rowAddButton);

    database::ConnectionParameters params = {"tcp:127.0.0.1", database::AuthenticationType::SqlPassword, "glaresheen", "CEaSa9b3Qa6HaYb9ba979aJ11VQI8a"};
    FilmTableModel* model = FilmTableModel::connect(params, this);

    QVBoxLayout* screenLayout = new QVBoxLayout(this);
    screenLayout->addLayout(actionBar);
    FilmTableView* table = new FilmTableView(screenLayout, model);

    QObject::connect(rowAddButton, &QPushButton::clicked, table, &FilmTableView::insertRow);
}
