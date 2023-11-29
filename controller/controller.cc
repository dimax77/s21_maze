#include "controller.h"
#include "memory"
#include "model/maze_state.h"

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
  }
}

void Controller::SetMazeView(MazeView *maze_view) { view_ = maze_view; }
