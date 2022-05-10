cmake_minimum_required(VERSION 3.22)
project(Lesson4Exercise3 C)

configure_file("input.txt" "${CMAKE_BINARY_DIR}/Lesson 4/Exercise 3/input.txt" COPYONLY)
add_executable(Lesson4Exercise3 main.c)