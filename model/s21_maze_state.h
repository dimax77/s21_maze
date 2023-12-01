#ifndef MAZE_STATE_H
#define MAZE_STATE_H

#include "dto/s21_dto.h"
#include "s21_observer.h"
#include <QVector>
#include <memory>

namespace s21 {
class MazeModel;
class Controller;
} // namespace s21

namespace s21 {
class MazeState : public Observable, std::enable_shared_from_this<MazeState> {

  friend MazeModel;
  friend Controller;

public:
  MazeState();
  virtual ~MazeState();

protected:
  QVector<QVector<int>> value_;
  ModelDTO maze_;

private:
  int state_id_;
};
} // namespace s21

#endif // MAZE_STATE_H
