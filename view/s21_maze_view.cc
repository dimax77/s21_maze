#include "s21_maze_view.h"
#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <QPen>

using namespace s21;

MazeView::MazeView(QWidget *parent) : QGraphicsView(parent) {
  setSceneRect(0, 0, scene_width, scene_height);
  setRenderHint(QPainter::Antialiasing);
  setFixedSize(scene_width + 10, scene_height + 10);
}

void MazeView::Draw(QVector<QVector<int>> &cave) {

  double cell_height = scene_height / cave.size();
  double cell_width = scene_width / cave[0].size();
  scene_.clear();

  QPen wall_pen(Qt::green, 2);

  for (int row = 0; row < cave.size(); ++row) {
    for (int col = 0; col < cave[row].size(); ++col) {
      if (cave[row][col] == 1) {
        QGraphicsRectItem *wall = new QGraphicsRectItem(
            col * cell_width, row * cell_height, cell_width, cell_height);
        wall->setPen(wall_pen);
        scene_.addItem(wall);
      }
    }
  }

  setScene(&scene_);
}

void MazeView::Draw(ViewDTO maze) {
  double cell_width = scene_height / maze.first.size();
  double cell_height = scene_width / maze.first[0].size();

  scene_.clear();

  QPen wall_pen(Qt::green, 2);

  int rows = maze.first.size();
  int cols = maze.first[0].size();

  auto upper_border = new QGraphicsLineItem(0, 0, cols * cell_width, 0);
  auto bottom_border = new QGraphicsLineItem(
      0, rows * cell_width, cols * cell_width, rows * cell_width);
  auto left_border = new QGraphicsLineItem(0, 0, 0, rows * cell_width);
  auto right_border = new QGraphicsLineItem(
      0, rows * cell_width, cols * cell_height, rows * cell_height);

  upper_border->setPen(wall_pen);
  bottom_border->setPen(wall_pen);
  left_border->setPen(wall_pen);
  right_border->setPen(wall_pen);

  scene_.addItem(upper_border);
  scene_.addItem(bottom_border);
  scene_.addItem(left_border);
  scene_.addItem(right_border);

  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      if (maze.first[r][c]) {
        auto right_wall =
            new QGraphicsLineItem((c + 1) * cell_width, r * cell_height,
                                  (c + 1) * cell_width, (r + 1) * cell_height);
        right_wall->setPen(wall_pen);
        scene_.addItem(right_wall);
      }
    }
  }

  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      if (maze.second[r][c]) {
        auto bottom_wall =
            new QGraphicsLineItem(c * cell_width, (r + 1) * cell_height,
                                  (c + 1) * cell_width, (r + 1) * cell_height);
        bottom_wall->setPen(wall_pen);
        scene_.addItem(bottom_wall);
      }
    }
  }
  setScene(&scene_);
}
