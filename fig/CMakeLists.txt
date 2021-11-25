cmake_minimum_required(VERSION 3.20)
project(fig)

set(CMAKE_CXX_STANDARD 14)

add_executable(fig main.cpp figure_lib/Figure.cpp figure_lib/Figure.h figure_lib/Rectangle.cpp figure_lib/Rectangle.h figure_lib/Ellipse.cpp figure_lib/Ellipse.h figure_lib/Triangle.cpp figure_lib/Triangle.h figure_lib/Polygon.cpp figure_lib/Polygon.h)
