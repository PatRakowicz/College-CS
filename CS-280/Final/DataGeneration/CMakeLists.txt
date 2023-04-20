cmake_minimum_required(VERSION 3.25)
project(CS280_DataGeneration)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CS280_DataGeneration
        invGenerator.h
        main.cpp
        data.csv)
