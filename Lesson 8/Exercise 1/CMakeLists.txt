cmake_minimum_required(VERSION 3.22)
project(Lesson8Exercise1 C)

configure_file("mappa.txt" "${CMAKE_BINARY_DIR}/Lesson 8/Exercise 1/mappa.txt" COPYONLY)
add_executable(Lesson8Exercise1 main.c)