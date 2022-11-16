cmake_minimum_required(VERSION 3.23)
project(Inher)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Inher
        main.cpp Bears.h Animal.h)
