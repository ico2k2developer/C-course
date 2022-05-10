cmake_minimum_required(VERSION 3.22)
project(Lesson2Exercise3 C)

configure_file("sorgente.txt" "${CMAKE_BINARY_DIR}/Lesson 2/Exercise 3/sorgente.txt" COPYONLY)
add_executable(Lesson2Exercise3 main.c)