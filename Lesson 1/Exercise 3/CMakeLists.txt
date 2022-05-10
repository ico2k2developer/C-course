cmake_minimum_required(VERSION 3.22)
project(Lesson1Exercise3 C)

configure_file("Bronte.txt" "${CMAKE_BINARY_DIR}/Lesson 1/Exercise 3/Bronte.txt" COPYONLY)
add_executable(Lesson1Exercise3 main.c)