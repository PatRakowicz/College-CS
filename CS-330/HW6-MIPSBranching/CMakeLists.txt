cmake_minimum_required(VERSION 3.26)
project(HW6_MIPSBranching)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW6_MIPSBranching
        pipeline_simulator.c
        program_pipelined2.txt)
