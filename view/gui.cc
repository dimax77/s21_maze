#include "gui.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGridLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>

using namespace s21;

QGraphicsScene *GUI::maze_scene_ = nullptr;

void GUI::Create(QWidget *parent) {
  maze_scene_ = new QGraphicsScene(parent);
  QGraphicsView *maze_graphics_view = new QGraphicsView(maze_scene_, parent);
  maze_graphics_view->setMinimumSize(800, 600);

  QSpinBox *maze_height_adjust = new QSpinBox(parent);
  QSpinBox *maze_width_adjust = new QSpinBox(parent);

  QPushButton *load_maze = new QPushButton("Load Maze", parent);
  QPushButton *save_maze = new QPushButton("Save Maze", parent);
  QPushButton *generate_maze = new QPushButton("Generate Maze", parent);

  QGridLayout *main_layout = new QGridLayout(parent);

  main_layout->addWidget(maze_graphics_view, 1, 1);

  QWidget *control_container = new QWidget(parent);
  QGridLayout *control_layout = new QGridLayout(control_container);
  main_layout->addWidget(control_container, 1, 2);

  control_layout->addWidget(maze_height_adjust, 1, 1);
  control_layout->addWidget(maze_width_adjust, 1, 2);
  control_layout->addWidget(load_maze, 2, 1);
  control_layout->addWidget(save_maze, 2, 2);
  control_layout->addWidget(generate_maze, 2, 3);
}
