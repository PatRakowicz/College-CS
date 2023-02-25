cmake_minimum_required(VERSION 3.24)
project(HW4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW4
        bst.h
        hw4-starter.cpp
        movies.txt)
