#ifndef MAZESTATE_H
#define MAZESTATE_H

//#include "maze_model.h"
#include "observer.h"
#include <QVector>

namespace s21 {
class MazeModel;
class Controller;
} // namespace s21

namespace s21 {
class MazeState : public Observable {

  friend MazeModel;
  friend Controller;

public:
  MazeState();
  virtual ~MazeState();
  //  void Notify(int state_id) override;

protected:
  QVector<QVector<int>> maze_state_;

private:
  int state_id_;
};
} // namespace s21

#endif // MAZESTATE_H
