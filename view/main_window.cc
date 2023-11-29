#include "main_window.h"
#include "controller/controller.h"
#include "gui.h"
#include "iostream"
#include "maze_view.h"

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
  //  connect(load_btn_, &QPushButton::clicked, this,
  //  &MainWindow::HandleLoadMaze); connect(save_btn_, &QPushButton::clicked,
  //  this, &MainWindow::HandleSaveMaze);
}

void MainWindow::OnLoad() { controller_->GenerateMaze(10, 10); }

void MainWindow::HandleGenerateMaze() {
  std::cout << "Generate maze button pressed\n";
  controller_->GenerateMaze(GUI::GetHeightSpin()->value(),
                            GUI::GetWidthSpin()->value());
}
