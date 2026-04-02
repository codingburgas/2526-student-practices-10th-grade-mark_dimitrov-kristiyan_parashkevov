#include "mainwindow.h"
#include "filmsscreen.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setCentralWidget(new FilmsScreen(this));
}
