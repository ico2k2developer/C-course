cmake_minimum_required(VERSION 3.22)
project(Lesson4Exercise1 C)

configure_file("input.txt" "${CMAKE_BINARY_DIR}/Lesson 4/Exercise 1/input.txt" COPYONLY)
add_executable(Lesson4Exercise1 main.c)