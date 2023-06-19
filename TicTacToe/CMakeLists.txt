cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)

include("./Ansi-Text-Manipulation-Library/AnsiTextLibrary/CMakeLists.txt")

project(TicTacToe)

set(SOURCES
    src/main.cpp
    src/board.cpp
    src/board.h
    src/game.cpp
    src/game.h


)

add_executable(TicTacToe ${SOURCES})
target_link_libraries(TicTacToe AnsiTextManipulationLibrary)