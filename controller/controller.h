#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/maze_model.h"
#include "model/maze_state.h"
#include "model/observer.h"
#include "view/maze_view.h"

namespace s21 {
class MainWindow;
}

namespace s21 {

class Controller : public Observer {

  friend class MainWindow;

public:
  Controller();
  ~Controller();
  void Update(int state_id) override;
  void GenerateMaze(int height, int width);

protected:
  void SetMazeView(MazeView *maze_view);

private:
  MazeView *view_;
  MazeModel *model_;
  MazeState *state_;
};
} // namespace s21

#endif // CONTROLLER_H
