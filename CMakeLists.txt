cmake_minimum_required(VERSION 3.14)

project(maze LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES main.cpp
    view/s21_main_window.h
    view/s21_main_window.cc
    view/s21_maze_view.h view/s21_maze_view.cc
    model/s21_observer.h model/s21_observer.cc
    view/s21_gui.h view/s21_gui.cc
    controller/s21_controller.h controller/s21_controller.cc
    model/s21_maze_state.h model/s21_maze_state.cc
    model/s21_maze_model.h model/s21_maze_model.cc
    dto/s21_dto.h
    model/s21_io.h model/s21_io.cc
    adapter/s21_adapter.h adapter/s21_adapter.cc
    model/s21_ellers_algorithm.h model/s21_ellers_algorithm.cc)

add_executable(maze
   ${PROJECT_SOURCES}
)
target_link_libraries(maze Qt${QT_VERSION_MAJOR}::Widgets)
