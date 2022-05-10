cmake_minimum_required(VERSION 3.22)
project(Lesson7Exercise2 C)

configure_file("sort.txt" "${CMAKE_BINARY_DIR}/Lesson 7/Exercise 2/sort.txt" COPYONLY)
add_executable(Lesson7Exercise2 main.c)