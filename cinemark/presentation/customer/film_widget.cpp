#include "film_widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

FilmWidget::FilmWidget(Film film, QWidget* parent)
    : QWidget(parent)
    , film(film)
{
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setSpacing(25);

    QLabel* poster = new QLabel(this);
    poster->setPixmap(QPixmap(film.poster).scaled(100, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QVBoxLayout* filmInfo = new QVBoxLayout;
    QLabel* title = new QLabel(film.title);
    title->setStyleSheet("font-size: 24pt");
    filmInfo->addWidget(title);
    filmInfo->addWidget(new QLabel(QString("Genre: ") + film.genre));

    QPushButton* buy = new QPushButton("Buy Ticket");
    QObject::connect(buy, &QPushButton::clicked, this, [this]{emit buyPressed(this->film);});

    layout->addWidget(poster);
    layout->addLayout(filmInfo, 1);
    layout->addWidget(buy);
}
