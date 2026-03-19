#include "filmsscreen.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTableWidget>

FilmsScreen::FilmsScreen(QWidget* parent)
    : QWidget(parent)
{
    QHBoxLayout* actionBar = new QHBoxLayout;
    actionBar->addWidget(new QLineEdit);
    actionBar->addWidget(new QPushButton("+"));

    QVBoxLayout* screenLayout = new QVBoxLayout(this);
    screenLayout->addLayout(actionBar);
    screenLayout->addWidget(new QTableWidget(3, 3, this));
}
