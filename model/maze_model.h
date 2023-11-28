#ifndef MAZE_MODEL_H
#define MAZE_MODEL_H

#include "controller/controller.h"
#include "maze_state.h"

namespace s21 {
class MazeModel {

  friend Controller;

public:
  explicit MazeModel(MazeState *maze_state);

protected:
  void GenerateMaze(int height, int width);

private:
  MazeState *maze_state_;
};

} // namespace s21
#endif // MAZE_MODEL_H
