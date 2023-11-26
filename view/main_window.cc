#include "main_window.h"

using namespace s21;

MainWindow::MainWindow(QWidget *parent) : QMainWindow{parent} { SetupIU(); }

void MainWindow::SetupIU() { this->setGeometry(400, 300, 900, 600); }
