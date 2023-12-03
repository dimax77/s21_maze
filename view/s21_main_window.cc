#include "s21_main_window.h"
#include "controller/s21_controller.h"
#include "dto/s21_dto.h"
#include "iostream"
#include "s21_gui.h"
#include "s21_maze_view.h"
#include <QFileDialog>
#include <QString>
using namespace s21;

MainWindow::MainWindow(Controller *controller, QWidget *parent)
    : QMainWindow{parent}, controller_(controller) {
  SetupUI();
  controller->SetMazeView(maze_scene_);
  OnLoad();
}

void MainWindow::SetupUI() {
  QWidget *central_widget = new QWidget(this);
  setCentralWidget(central_widget);

  GUI::Create(central_widget);
  setGeometry(400, 300, 900, 600);

  generate_btn_ = GUI::GetGenerateButton();
  load_btn_ = GUI::GetLoadButton();
  save_btn_ = GUI::GetSaveButton();

  maze_scene_ = GUI::GetMazeScene();

  if (connect(generate_btn_, &QPushButton::clicked, this,
              &MainWindow::HandleGenerateMaze)) {
    std::cout << "Connection established\n";
  }
  connect(load_btn_, &QPushButton::clicked, this, &MainWindow::HandleLoadMaze);
  // connect(save_btn_, &QPushButton::clicked,
  //   this, &MainWindow::HandleSaveMaze);
}

void MainWindow::OnLoad() { controller_->GenerateMaze(10, 10); }

void MainWindow::HandleGenerateMaze() {
  if (GUI::GetHeightSpin()->value() > 0 && GUI::GetWidthSpin()->value() > 0) {
    std::cout << "Generate maze button pressed\n";
    controller_->GenerateMaze(GUI::GetHeightSpin()->value(),
                              GUI::GetWidthSpin()->value());
  }
}

void MainWindow::HandleLoadMaze() {
  QString file_path = QFileDialog::getOpenFileName(
      this, tr("Open Maze File"), "", tr("Maze Files (*.s21_maze)"));
  if (!file_path.isEmpty()) {
    controller_->LoadMaze(file_path);
  }
}
