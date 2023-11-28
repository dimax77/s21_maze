#ifndef MAZE_VIEW_H
#define MAZE_VIEW_H

#include <QGraphicsView>
#include <QVector>

namespace s21 {

class MazeView : public QGraphicsView {
  Q_OBJECT
public:
  friend class Controller;
  MazeView(QWidget *parent = nullptr);

protected:
  void Draw(QVector<QVector<int>> &maze);
  QGraphicsScene scene_;
};

} // namespace s21
#endif // MAZE_VIEW_H
