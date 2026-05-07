#include "main_window.h"
#include "film_editor.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setCentralWidget(new FilmEditor(this));
}
