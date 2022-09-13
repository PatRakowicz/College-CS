cmake_minimum_required(VERSION 3.21)
project(Linked_List)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Linked_List
        LinkedList.cpp
        LinkedList.h LinkedListTask.cpp)
