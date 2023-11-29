#ifndef MAZE_STATE_H
#define MAZE_STATE_H

//#include "maze_model.h"
#include "observer.h"
#include <QVector>
#include <memory>

namespace s21 {
class MazeModel;
class Controller;
} // namespace s21

namespace s21 {
class MazeState : public Observable, std::enable_shared_from_this<MazeModel> {

  friend MazeModel;
  friend Controller;

public:
  MazeState();
  virtual ~MazeState();
  //    void Notify(int state_id) override;

protected:
  QVector<QVector<int>> value_;

private:
  int state_id_;
};
} // namespace s21

#endif // MAZE_STATE_H
