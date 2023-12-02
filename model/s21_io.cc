#include "s21_io.h"
#include "dto/s21_dto.h"
#include <QVector>
#include <fstream>
#include <iostream>

using namespace s21;

ModelDTO IO::LoadMaze(QString &file_name) {
  std::ifstream file(file_name.toStdString());
  if (!file.is_open()) {
    throw("Error opening file");
  }

  int rows, cols;
  ModelDTO maze;

  try {
    file >> rows >> cols;
    std::cout << "Rows: " << rows << " Cols: " << cols << std::endl;
    if (rows <= 0 || cols <= 0) {
      if (file.is_open())
        file.close();
      throw("Invalid maze dimension");
    }
    maze.resize(rows);
    for (int i = 0; i < rows; ++i)
      maze[i].resize(cols);
    for (int row = 0; row < rows; ++row)
      for (int col = 0; col < cols; ++col) {
        int value;
        file >> value;
        maze[row][col].right_wall = (value == 1);
      }

    for (int row = 0; row < rows; ++row)
      for (int col = 0; col < cols; ++col) {
        int value;
        file >> value;
        maze[row][col].bottom_line = (value == 1);
      }

  } catch (std::exception &e) {
    if (file.is_open())
      throw;
  }
  file.close();
  return maze;
}
