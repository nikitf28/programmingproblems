cmake_minimum_required(VERSION 3.20)
project(fig)

set(CMAKE_CXX_STANDARD 14)

add_executable(fig main.cpp Figure.cpp Figure.h)
