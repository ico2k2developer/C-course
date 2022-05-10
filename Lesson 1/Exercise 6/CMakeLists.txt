cmake_minimum_required(VERSION 3.22)
project(Lesson1Exercise6 C)

configure_file("Operations.txt" "${CMAKE_BINARY_DIR}/Lesson 1/Exercise 6/Operations.txt" COPYONLY)
add_executable(Lesson1Exercise6 main.c)