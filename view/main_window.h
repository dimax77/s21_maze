#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "maze_view.h"
#include <QGraphicsScene>
#include <QGridLayout>
#include <QMainWindow>
#include <QPushButton>

namespace s21 {
class MainWindow : public QMainWindow {
  Q_OBJECT
  friend class GUI;

public:
  explicit MainWindow(QWidget *parent = nullptr);

private:
  void SetupUI();
};

} // namespace s21
#endif // MAIN_WINDOW_H
