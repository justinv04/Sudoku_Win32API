cmake_minimum_required(VERSION 3.15)
project(Sudoku)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_compile_options(-Wall -Wextra -pedantic -g)
add_executable(sudoku main.cpp Sudoku.cpp Cell.cpp SudokuSolver.cpp)

set(CMAKE_VERBOSE_MAKEFILE OFF)