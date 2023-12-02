#ifndef S21_ELLERS_ALGORITHM_H
#define S21_ELLERS_ALGORITHM_H
#include "dto/s21_dto.h"

namespace s21 {

class EllersAlgorithm {
public:
  static ModelDTO CreateMaze(int height, int width);
  static void Classify(QVector<Cell> &row);
};

} // namespace s21

#endif // S21_ELLERS_ALGORITHM_H
