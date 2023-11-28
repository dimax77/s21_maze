#include "gui.h"
#include "maze_view.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>

using namespace s21;

MazeView *GUI::maze_scene_ = nullptr;

QPushButton *GUI::generate_btn_ = nullptr;
QPushButton *GUI::load_btn_ = nullptr;
QPushButton *GUI::save_btn_ = nullptr;

QSpinBox *GUI::height_set_spin_ = nullptr;
QSpinBox *GUI::width_set_spin_ = nullptr;

void GUI::Create(QWidget *parent) {

  QLabel *height_set_lbl = new QLabel("Set Height", parent);
  QLabel *width_set_lbl = new QLabel("Set Width", parent);
  QLabel *stat_info_lbl = new QLabel("Statistics will be placed here", parent);

  height_set_spin_ = new QSpinBox(parent);
  width_set_spin_ = new QSpinBox(parent);

  load_btn_ = new QPushButton("Load Maze", parent);
  save_btn_ = new QPushButton("Save Maze", parent);
  generate_btn_ = new QPushButton("Generate Maze", parent);

  QWidget *maze_container = new QWidget(parent);
  QWidget *control_container = new QWidget(parent);
  QWidget *upper_container = new QWidget(control_container);
  QWidget *central_container = new QWidget(control_container);
  QWidget *bottom_container = new QWidget(control_container);
  QWidget *stat_container = new QWidget(control_container);

  QGridLayout *main_layout = new QGridLayout(parent);
  QGridLayout *control_layout = new QGridLayout(control_container);
  QGridLayout *upper_layout = new QGridLayout(upper_container);
  QGridLayout *central_layout = new QGridLayout(central_container);
  QGridLayout *bottom_layout = new QGridLayout(bottom_container);
  QGridLayout *stat_layout = new QGridLayout(stat_container);
  QGridLayout *maze_layout = new QGridLayout(maze_container);

  maze_scene_ = new MazeView(maze_container);

  maze_layout->addWidget(maze_scene_);
  maze_container->setMinimumSize(500, 500);

  main_layout->addWidget(maze_container, 1, 1);
  main_layout->addWidget(control_container, 1, 2);

  control_layout->addWidget(upper_container, 1, 1);
  control_layout->addWidget(central_container, 2, 1);
  control_layout->addWidget(bottom_container, 3, 1);
  control_layout->addWidget(stat_container, 4, 1);

  upper_layout->addWidget(height_set_spin_, 1, 1);
  upper_layout->addWidget(width_set_spin_, 1, 2);
  upper_layout->addWidget(height_set_lbl, 2, 1);
  upper_layout->addWidget(width_set_lbl, 2, 2);

  central_layout->addWidget(generate_btn_, 1, 1);

  bottom_layout->addWidget(load_btn_, 1, 1);
  bottom_layout->addWidget(save_btn_, 1, 2);

  stat_layout->addWidget(stat_info_lbl, 1, 1);
}

QPushButton *GUI::GetGenerateButton() { return generate_btn_; }

QPushButton *GUI::GetLoadButton() { return load_btn_; }

QPushButton *GUI::GetSaveButton() { return save_btn_; }

QSpinBox *GUI::GetWidthSpin() { return width_set_spin_; }

QSpinBox *GUI::GetHeightSpin() { return height_set_spin_; }

MazeView *GUI::GetMazeScene() { return maze_scene_; }
