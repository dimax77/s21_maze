#ifndef GUI_H
#define GUI_H
#include "maze_view.h"
#include <QGraphicsScene>
#include <QPushButton>
#include <QSpinBox>
#include <QWidget>

namespace s21 {
class GUI {

public:
  static void Create(QWidget *parent);

  static QPushButton *GetGenerateButton();
  static QPushButton *GetLoadButton();
  static QPushButton *GetSaveButton();

  static QSpinBox *GetHeightSpin();
  static QSpinBox *GetWidthSpin();

  static MazeView *GetMazeScene();

private:
  static MazeView *maze_scene_;

  static QPushButton *generate_btn_;
  static QPushButton *load_btn_;
  static QPushButton *save_btn_;

  static QSpinBox *height_set_spin_;
  static QSpinBox *width_set_spin_;
};

} // namespace s21
#endif // GUI_H
