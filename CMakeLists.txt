cmake_minimum_required(VERSION 3.24)
project(Softeer_Practice)

set(CMAKE_CXX_STANDARD 17)

add_executable(Softeer_Practice virus.cpp complex_assemble_line.cpp buisiness_processing.cpp safecracker.cpp distance_driven.cpp obstacle_recognition.cpp test.cpp test.cpp)

add_compile_definitions(LOCAL_DEBUG)
add_executable(complex_assemble_line complex_assemble_line.cpp)
add_executable(score_assesment score_assesment.cpp)
add_executable(buisiness_processing buisiness_processing.cpp)
add_executable(safecracker safecracker.cpp)
add_executable(distance_driven distance_driven.cpp)

add_executable(obstacle_recognition obstacle_recognition.cpp)
add_executable(test test.cpp)