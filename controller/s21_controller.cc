#include "s21_controller.h"
#include "adapter/s21_adapter.h"
#include "memory"
#include "model/s21_io.h"
#include "model/s21_maze_state.h"

using namespace s21;

Controller::Controller() {
  auto state = new MazeState();
  state_ = std::shared_ptr<MazeState>(state);
  state = nullptr;

  model_ = std::unique_ptr<MazeModel>(std::move(new MazeModel(state_)));

  state_->AddObserver(this);
}

void Controller::GenerateMaze(int height, int width) {
  model_->GenerateMaze(height, width);
}

void Controller::Update(int state_id) {
  switch (state_id) {
  case 1:
    view_->Draw(state_->value_);
    break;
  case 2:
    auto maze = Adapter::ConvertForView(state_->maze_);
    view_->Draw(maze);
  }
}

void Controller::SetMazeView(MazeView *maze_view) { view_ = maze_view; }

void Controller::LoadMaze(QString &file_name) { model_->LoadMaze(file_name); }
