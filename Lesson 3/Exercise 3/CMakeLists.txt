cmake_minimum_required(VERSION 3.22)
project(Lesson3Exercise3 C)

configure_file("numeri.txt" "${CMAKE_BINARY_DIR}/Lesson 3/Exercise 3/numeri.txt" COPYONLY)
add_executable(Lesson3Exercise3 main.c)