#ifndef S21_DTO_H
#define S21_DTO_H
#include "utility"
#include <QVector>

namespace s21 {

struct Cell {
  bool right_wall;
  bool left_wall;
  bool top_line;
  int bottom_line;
  bool visited;
  int cell_class;
  Cell()
      : right_wall(false), left_wall(false), top_line(false),
        bottom_line(false), visited(false), cell_class(0) {}
};

using ViewDTO = std::pair<QVector<QVector<bool>>, QVector<QVector<bool>>>;
using ModelDTO = QVector<QVector<Cell>>;
} // namespace s21
#endif // S21_DTO_H
