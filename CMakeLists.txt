# cmake_minimum_required(VERSION <specify CMake version here>)
project(sandbox)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++17 -Wall -Wextra -Werror")

add_executable(
        sandbox
#        coursera/cpp-yellow-belt/week02/01_Decomposition/starter.cpp
        main.cpp
        reload.h
)