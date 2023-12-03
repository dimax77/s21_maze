#ifndef MAZE_VIEW_H
#define MAZE_VIEW_H

#include "dto/s21_dto.h"
#include <QGraphicsView>
#include <QVector>

namespace s21 {

class MazeView : public QGraphicsView {
  Q_OBJECT
public:
  static constexpr int scene_height = 500;
  static constexpr int scene_width = 500;
  friend class Controller;
  MazeView(QWidget *parent = nullptr);

protected:
  void Draw(QVector<QVector<int>> &cave);
  void Draw(ViewDTO maze);
  QGraphicsScene scene_;
};

} // namespace s21
#endif // MAZE_VIEW_H
