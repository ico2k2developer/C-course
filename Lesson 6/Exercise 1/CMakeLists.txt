cmake_minimum_required(VERSION 3.22)
project(Lesson6Exercise1 C)

configure_file("corse.txt" "${CMAKE_BINARY_DIR}/Lesson 6/Exercise 1/corse.txt" COPYONLY)
add_executable(Lesson6Exercise1 main.c)