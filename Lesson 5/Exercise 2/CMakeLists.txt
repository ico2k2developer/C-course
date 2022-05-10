cmake_minimum_required(VERSION 3.22)
project(Lesson5Exercise2 C)

configure_file("sorgente.txt" "${CMAKE_BINARY_DIR}/Lesson 5/Exercise 2/sorgente.txt" COPYONLY)
configure_file("dizionario.txt" "${CMAKE_BINARY_DIR}/Lesson 5/Exercise 2/dizionario.txt" COPYONLY)
add_executable(Lesson5Exercise2 main.c)