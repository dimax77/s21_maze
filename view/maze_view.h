#ifndef MAZE_VIEW_H
#define MAZE_VIEW_H

#include <QGraphicsView>
namespace s21 {

class MazeView : public QGraphicsView {
  Q_OBJECT
public:
  MazeView(QWidget *parent = nullptr);

private:
  QGraphicsScene scene_;
};

} // namespace s21
#endif // MAZE_VIEW_H
