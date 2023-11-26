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
public:
  explicit MainWindow(QWidget *parent = nullptr);

private:
  void SetupIU();

  MazeView *maze_view_;
  QGridLayout *main_layout_;
  QPushButton *generate_btn_;
  QPushButton *load_btn_;
  QPushButton *save_btn_;

signals:
};

} // namespace s21
#endif // MAIN_WINDOW_H
