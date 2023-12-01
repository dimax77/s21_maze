#ifndef MAZE_MODEL_H
#define MAZE_MODEL_H

#include "controller/s21_controller.h"
#include "dto/s21_dto.h"
#include "memory"
#include "s21_maze_state.h"

namespace s21 {
class MazeModel {

  friend Controller;

public:
  explicit MazeModel(std::shared_ptr<MazeState> state);

protected:
  void GenerateMaze(int height, int width);
  void LoadMaze(QString &file_name);

private:
  std::shared_ptr<MazeState> state_;
};

} // namespace s21
#endif // MAZE_MODEL_H
