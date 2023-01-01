cmake_minimum_required(VERSION 3.24)
project(Softeer_Practice)

set(CMAKE_CXX_STANDARD 17)

add_executable(Softeer_Practice virus.cpp complex_assemble_line.cpp)

add_compile_definitions(LOCAL_DEBUG)
add_executable(complex_assemble_line complex_assemble_line.cpp)