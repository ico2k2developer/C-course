cmake_minimum_required(VERSION 3.22)
project(ExamExercise6 C)

configure_file("bills.txt" "${CMAKE_BINARY_DIR}/Exam/Exercise 6/bills.txt" COPYONLY)
add_executable(ExamExercise6 main.c)