cmake_minimum_required(VERSION 3.23)
project(Lab13)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab13
        Shapes.cpp
        Rectangle.h
        Square.h)
