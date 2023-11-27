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
    view/main_window.h
    view/main_window.cc
    view/maze_view.h view/maze_view.cc
    model/observer.h model/observer.cpp
    view/gui.h view/gui.cc)

add_executable(maze
   ${PROJECT_SOURCES}
)
target_link_libraries(maze Qt${QT_VERSION_MAJOR}::Widgets)
