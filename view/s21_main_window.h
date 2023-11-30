#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "controller/s21_controller.h"
#include "s21_maze_view.h"
#include <QGraphicsScene>
#include <QGridLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>

namespace s21 {
class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(Controller *controller, QWidget *parent = nullptr);

private:
  void SetupUI();
  void OnLoad();

  void HandleGenerateMaze();
  void HandleLoadMaze();
  void HandleSaveMaze();

  QPushButton *generate_btn_;
  QPushButton *load_btn_;
  QPushButton *save_btn_;

  Controller *controller_;

  MazeView *maze_scene_;
};

} // namespace s21
#endif // MAIN_WINDOW_H
