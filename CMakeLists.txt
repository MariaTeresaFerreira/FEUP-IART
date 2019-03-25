cmake_minimum_required(VERSION 3.7)
project(FEUP_IART)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Piece.cpp Piece.h Cell.cpp Cell.h Board.cpp Board.h)
add_executable(FEUP_IART ${SOURCE_FILES})