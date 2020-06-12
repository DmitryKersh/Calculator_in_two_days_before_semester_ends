cmake_minimum_required(VERSION 3.14)
project(Calculator_in_two_days_before_semester_ends)

set(CMAKE_CXX_STANDARD 14)

add_executable(Calculator_in_two_days_before_semester_ends main.cpp
        UnaryOperation.h
        Operation.h UnaryOperations.h BinaryOperation.h BinaryOperations.h Parser.h Enum_operations.h)