#include "../main_window.h"
#include "films_page.h"
#include "user_controller.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    User testUser = UserController::getUser("test", "testpwd");
    setCentralWidget(new FilmsPage(testUser, this));
}
