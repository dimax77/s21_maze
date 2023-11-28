#include "maze_view.h"
#include <QGraphicsItem>
#include <QPen>

using namespace s21;

MazeView::MazeView(QWidget *parent) : QGraphicsView(parent) {}

void MazeView::Draw(QVector<QVector<int>> &maze) {
  scene_.clear();

  QPen wall_pen(Qt::green, 2);

  for (int row = 0; row < maze.size(); ++row) {
    for (int col = 0; col < maze[row].size(); ++col) {
      if (maze[row][col] == 1) {
        QGraphicsRectItem *wall =
            new QGraphicsRectItem(col * 10, row * 10, 10, 10);
        wall->setPen(wall_pen);
        scene_.addItem(wall);
      }
    }
  }

  setScene(&scene_);
}
