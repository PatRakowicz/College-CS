cmake_minimum_required(VERSION 3.24)
project(HW2_colorDB)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW2_colorDB
        colors.txt
        SQLscript.cpp)
