#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "memory"
#include "model/s21_maze_model.h"
#include "model/s21_maze_state.h"
#include "model/s21_observer.h"
#include "view/s21_maze_view.h"

namespace s21 {
class MainWindow;
}

namespace s21 {

class Controller : public Observer {

  friend class MainWindow;

public:
  Controller();
  void Update(int state_id) override;
  void LoadMaze(QString &file_name);
  void GenerateMaze(int height, int width);

protected:
  void SetMazeView(MazeView *maze_view);

private:
  std::unique_ptr<MazeModel> model_;
  std::shared_ptr<MazeState> state_;

  MazeView *view_;
};
} // namespace s21

#endif // CONTROLLER_H
