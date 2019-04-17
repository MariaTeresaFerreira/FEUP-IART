cmake_minimum_required(VERSION 3.7)
project(mini_teste_2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Board.cpp Board.h Game.cpp Game.h)
add_executable(mini_teste_2 ${SOURCE_FILES})