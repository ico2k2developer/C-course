cmake_minimum_required(VERSION 3.22)
project(Lesson1Exercise2 C)

configure_file("Guide.txt" "${CMAKE_BINARY_DIR}/Lesson 1/Exercise 2/Guide.txt" COPYONLY)
add_executable(Lesson1Exercise2 main.c)