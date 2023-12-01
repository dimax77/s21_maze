#ifndef S21_ADAPTER_H
#define S21_ADAPTER_H
#include "dto/s21_dto.h"

namespace s21 {
class Adapter {
public:
  static ViewDTO ConvertForView(ModelDTO &maze);
};
} // namespace s21

#endif // S21_ADAPTER_H
