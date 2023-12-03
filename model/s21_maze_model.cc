#include "s21_maze_model.h"
#include "memory"
#include "s21_ellers_algorithm.h"
#include "s21_io.h"
#include "s21_maze_state.h"

using namespace s21;

MazeModel::MazeModel(std::shared_ptr<MazeState> state) : state_(state) {}

void MazeModel::GenerateMaze(int height, int width) {
  //  auto test_maze = QVector(height, QVector<int>(width, 1));
  //  state_->value_ = test_maze;
  //  state_->Notify(1);
  state_->maze_ = EllersAlgorithm::CreateMaze(height, width);
  state_->Notify(2);
}

void MazeModel::LoadMaze(QString &file_name) {
  state_->maze_ = IO::LoadMaze(file_name);
  state_->Notify(2);
}
