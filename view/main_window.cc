#include "main_window.h"
#include "gui.h"

using namespace s21;

MainWindow::MainWindow(QWidget *parent) : QMainWindow{parent} { SetupUI(); }

void MainWindow::SetupUI() {
  QWidget *central_widget = new QWidget(this);
  setCentralWidget(central_widget);
  GUI::Create(central_widget);
  setGeometry(400, 300, 900, 600);
}
