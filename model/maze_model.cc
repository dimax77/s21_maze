#include "maze_model.h"
#include "iostream"
#include "maze_state.h"
#include "memory"

using namespace s21;

MazeModel::MazeModel(std::shared_ptr<MazeState> state) : state_(state) {
  std::cout << "Model created.\n";
}

void MazeModel::GenerateMaze(int height, int width) {
  auto v = QVector(height, QVector<int>(width, 1));
  for (int r = 0; r < height; ++r) {
    for (int c = 0; c < width; ++c) {
      std::cout << v[r][c];
    }
    std::cout << std::endl;
  }
  if (state_) {
    std::cout << "Trying draw maze..\n";
    state_->value_ = v;

    state_->Notify(1);
  } else {
    std::cout << "Maze State is uninitialized.\n ";
  }
}
