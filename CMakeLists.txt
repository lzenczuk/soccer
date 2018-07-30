cmake_minimum_required(VERSION 3.10)
project(soccer)

set(CMAKE_CXX_STANDARD 11)

add_executable(soccer main.cpp)
add_executable(soccer_test board_test.cpp)