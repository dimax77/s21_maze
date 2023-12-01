#include "s21_adapter.h"

#include "dto/s21_dto.h"
#include <utility>

using namespace s21;

ViewDTO Adapter::ConvertForView(ModelDTO &maze) {
  auto cols = maze[0].size();
  auto rows = maze.size();

  QVector<QVector<bool>> r_w(rows, QVector<bool>(cols, false));
  QVector<QVector<bool>> b_w(rows, QVector<bool>(cols, false));

  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      if (maze[r][c].right_wall)
        r_w[r][c] = true;
      if (maze[r][c].bottom_wall)
        b_w[r][c] = true;
    }
  }
  return std::make_pair(r_w, b_w);
}
