cmake_minimum_required(VERSION 3.10)
project(soccer)

set(CMAKE_CXX_STANDARD 11)

add_executable(soccer main.cpp)
add_executable(pitch_array_test test_pitch_array.cpp pitch_array.cpp)
add_executable(pitch_test test_pitch.cpp pitch.cpp pitch_array.cpp)
add_executable(match_test test_match.cpp pitch.cpp pitch_array.cpp match.cpp)
