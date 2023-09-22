cmake_minimum_required(VERSION 3.26)
project(HW5_Pipelining)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW5_Pipelining
        pipeline_simulator.c
        program_pipelined.txt)
