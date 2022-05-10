cmake_minimum_required(VERSION 3.22)
project(Lesson3Exercise1 C)

configure_file("input.txt" "${CMAKE_BINARY_DIR}/Lesson 3/Exercise 1/input.txt" COPYONLY)
add_executable(Lesson3Exercise1 main.c)