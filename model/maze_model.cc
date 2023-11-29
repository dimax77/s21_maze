#include "maze_model.h"
#include "iostream"
#include "maze_state.h"
#include "memory"

using namespace s21;

MazeModel::MazeModel(std::shared_ptr<MazeState> state) : state_(state) {
  std::cout << "Model created.\n";
}

void MazeModel::GenerateMaze(int height, int width) {
  auto test_maze = QVector(height, QVector<int>(width, 1));
  state_->value_ = test_maze;
  state_->Notify(1);
}
