cmake_minimum_required(VERSION 3.22)
project(ExamExercise5 C)

configure_file("file.txt" "${CMAKE_BINARY_DIR}/Exam/Exercise 5/file.txt" COPYONLY)
add_executable(ExamExercise5 main.c)