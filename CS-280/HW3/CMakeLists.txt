cmake_minimum_required(VERSION 3.24)
project(HW3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW3
        cities.txt
        hw3-starter.cpp
        linkedList.h)
