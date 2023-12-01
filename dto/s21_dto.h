#ifndef S21_DTO_H
#define S21_DTO_H
#include "utility"
#include <QVector>

namespace s21 {

struct cell {
  bool right_wall;
  bool left_wall;
  bool top_wall;
  bool bottom_wall;
  bool visited;
};

using ViewDTO = std::pair<QVector<QVector<bool>>, QVector<QVector<bool>>>;
using ModelDTO = QVector<QVector<cell>>;
} // namespace s21
#endif // S21_DTO_H
