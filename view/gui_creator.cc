#include "gui_creator.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGridLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>

using namespace s21;

void GUI::Create(QWidget *parent) {
  QGraphicsScene *maze_scene = new QGraphicsScene(parent);
  QGraphicsView *maze_graphics_view = new QGraphicsView(maze_scene, parent);

  QSpinBox *height_adjust = new QSpinBox(parent);
}
