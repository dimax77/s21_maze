#ifndef GUI_H
#define GUI_H
#include <QGraphicsScene>
#include <QWidget>

namespace s21 {
class GUI {
  friend class controller;

public:
  static void Create(QWidget *parent);

protected:
  static QGraphicsScene *maze_scene_;
};

} // namespace s21
#endif // GUI_H
