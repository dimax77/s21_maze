#ifndef S21_IO_H
#define S21_IO_H
#include "dto/s21_dto.h"
#include <QString>

namespace s21 {
class IO {
public:
  //    s21_io();
  static ModelDTO LoadMaze(QString &file_name);
  static ModelDTO SaveMaze(QString &file_name);
};
} // namespace s21

#endif // S21_IO_H
