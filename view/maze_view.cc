#include "maze_view.h"
#include <QGraphicsItem>
#include <QPen>

using namespace s21;

MazeView::MazeView(QWidget *parent) : QGraphicsView(parent) {}

void MazeView::Draw(QVector<QVector<int>> &maze) {

  double cell_height = 500.0 / maze.size();
  double cell_width = 500.0 / maze[0].size();
  scene_.clear();

  QPen wall_pen(Qt::green, 2);

  for (int row = 0; row < maze.size(); ++row) {
    for (int col = 0; col < maze[row].size(); ++col) {
      if (maze[row][col] == 1) {
        QGraphicsRectItem *wall = new QGraphicsRectItem(
            col * cell_width, row * cell_height, cell_width, cell_height);
        wall->setPen(wall_pen);
        scene_.addItem(wall);
      }
    }
  }

  setScene(&scene_);
}
