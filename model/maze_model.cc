#include "maze_model.h"
#include "maze_state.h"

using namespace s21;

MazeModel::MazeModel(MazeState *maze_state) : maze_state_(maze_state) {}

void MazeModel::GenerateMaze(int height, int width) {
  auto v = QVector(height, QVector<int>(width, 1));
  maze_state_->maze_state_ = v;

  maze_state_->Notify(1);
}
