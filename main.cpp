#include "./view/s21_main_window.h"
#include "controller/s21_controller.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Controller controller;
  s21::MainWindow main_window(&controller);
  main_window.show();
  return a.exec();
}
