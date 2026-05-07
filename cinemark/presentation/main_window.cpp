#include "main_window.h"
#include "films_screen.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setCentralWidget(new FilmsScreen(this));
}
