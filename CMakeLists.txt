cmake_minimum_required(VERSION 3.10)
project(soccer)

set(CMAKE_CXX_STANDARD 11)

add_executable(soccer main.cpp)
add_executable(pitch_array_test pitch_array_test.cpp pitch_array.cpp)
add_executable(pitch_test pitch_test.cpp pitch.cpp pitch_array.cpp)
