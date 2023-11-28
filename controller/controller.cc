#include "controller.h"
#include "model/maze_state.h"

using namespace s21;

Controller::Controller() {
  state_ = new MazeState();
  model_ = new MazeModel(state_);

  state_->AddObserver(this);
}

Controller::~Controller() {
  if (state_)
    delete state_;
  if (model_)
    delete model_;
}

// Controller::~Controller() {}

void Controller::GenerateMaze(int height, int width) {
  model_->GenerateMaze(height, width);
}

void Controller::Update(int state_id) {
  switch (state_id) {
  case 1:
    view_->Draw(state_->maze_state_);
    break;
  }
}

void Controller::SetMazeView(MazeView *maze_view) { view_ = maze_view; }
