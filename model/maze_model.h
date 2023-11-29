#ifndef MAZE_MODEL_H
#define MAZE_MODEL_H

#include "controller/controller.h"
#include "maze_state.h"
#include "memory"

namespace s21 {
class MazeModel {

  friend Controller;

public:
  explicit MazeModel(std::shared_ptr<MazeState> state);

protected:
  void GenerateMaze(int height, int width);

private:
  std::shared_ptr<MazeState> state_;
};

} // namespace s21
#endif // MAZE_MODEL_H
