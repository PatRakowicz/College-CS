cmake_minimum_required(VERSION 3.26)
project(HW8_CacheSim)

set(CMAKE_CXX_STANDARD 14)

add_executable(HW8_CacheSim
        cache_sim.c
        mem_trace_long.txt
        mem_trace_long_result_5bit_3way.txt
        mem_trace_long_result_8bit_2way.txt
        mem_trace_small.txt
        mem_trace_small_result_4bit_3way.txt)
