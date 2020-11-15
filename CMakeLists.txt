# cmake_minimum_required(VERSION <specify CMake version here>)
project(sandbox)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++17 -Wall -Wextra -Werror")

add_executable(
        sandbox
        main.cpp
        test_runner.h test_runner.cpp
        coursera/cpp-yellow-belt/week03/02_phone_number/phone_number.h
        coursera/cpp-yellow-belt/week03/02_phone_number/phone_number.cpp
)