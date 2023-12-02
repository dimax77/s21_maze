#include "s21_ellers_algorithm.h"
#include "dto/s21_dto.h"
#include "iostream"
#include "random"
#include <QVector>

using namespace s21;

ModelDTO EllersAlgorithm::CreateMaze(int height, int width) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dis(0, 1);

  QVector<int> decisions(height * width * 2);

  for (auto &d : decisions) {
    d = dis(mt); // create decision's vector: random sequence of 1 and 0.
  }

  QVector<QVector<Cell>> maze(height,
                              QVector<Cell>(width, Cell())); // result maze

  int idx = 0;

  for (int row = 0; row < height; ++row) {

    QVector<Cell> tmp(width);

    if (row > 0) {
      tmp = maze[row - 1];
      for (auto &el : tmp) {
        el.right_wall = false;
        if (el.bottom_line) {
          el.bottom_line = 0;
          el.cell_class = 0;
        }
      }
    }

    Classify(tmp);

    for (int col = 0; col < width; ++col) { // setting right walls

      if (col == width - 1) {
        tmp[col].right_wall = true;
      } else {
        if (decisions[idx++]) { // decided to put the wall
          tmp[col].right_wall = true;
        } else if (col < width - 1) {
          if (tmp[col].cell_class ==
              tmp[col + 1].cell_class) { // decided not to put the wall
            tmp[col].right_wall = true;
          } else {
            tmp[col + 1].cell_class = tmp[col].cell_class;
          }
        }
      }
    }

    for (int col = 0; col < width; ++col) { // setting bottom
      if (row == height - 1) {
        tmp[col].bottom_line = true;
        //        if (col < width - 2) {
        //          if (tmp[col].right_wall &&
        //              (tmp[col + 1].cell_class != tmp[col].cell_class)) {
        //            tmp[col].right_wall = false;
        //            if (col < width - 2) {
        //              if (tmp[col + 1].cell_class == tmp[col + 2].cell_class
        //              &&
        //                  (tmp[col + 1].right_wall)) {
        //                tmp[col + 2].cell_class = tmp[col].cell_class;
        //              }
        //            }
        //            tmp[col + 1].cell_class = tmp[col].cell_class;
        //          }
        //        }
      } else {
        if (decisions[idx++]) { // decided put the bottom
          int count = col + 1;
          int bottoms = tmp[col].bottom_line;
          int elements = 0;
          if (count < width) {
            while (tmp[count].cell_class == tmp[col].cell_class) {
              bottoms += tmp[count++].bottom_line;
              ++elements;
              if (count == width)
                break;
            }
          }
          if (elements - bottoms > 1) {
            tmp[col].bottom_line = 1;
          }
        }
      }
    }

    maze[row] = tmp;
  }
  return maze;
}

void EllersAlgorithm::Classify(QVector<Cell> &row) {
  int cell_class = 1;
  for (auto &el : row) {
    if (!el.cell_class)
      el.cell_class = cell_class++;
  }
}
