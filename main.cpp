#include "./view/main_window.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::MainWindow main_window;
  main_window.show();
  return a.exec();
}
