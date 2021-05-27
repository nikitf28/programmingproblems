cmake_minimum_required(VERSION 3.19)
project(fraction2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(fraction2
        main.cpp
        rational.cpp
        rational.h)
