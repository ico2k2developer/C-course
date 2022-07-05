cmake_minimum_required(VERSION 3.22)
project(ExamExamplesExercise11 C)

configure_file("file.txt" "${CMAKE_BINARY_DIR}/Exam examples/Exercise 11/file.txt" COPYONLY)
add_executable(ExamExamplesExercise11 main.c)