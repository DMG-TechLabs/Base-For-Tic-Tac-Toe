cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)

include("./Ansi-Text-Manipulation-Library/AnsiTextLibrary/CMakeLists.txt")

project(TicTacToe)

set(SOURCES
    src/main.cpp

    src/game_structure/board.h
    src/game_structure/board.cpp

    src/utils/prompt.h
    src/utils/prompt.cpp
    src/utils/game_utils.h
    src/utils/game_utils.cpp
)

add_executable(TicTacToe ${SOURCES})
target_link_libraries(TicTacToe AnsiTextManipulationLibrary)