#include "board.h"

#include <iostream>
#include <string>

using namespace TicTacToe;

const char Board::X = 'X';
const char Board::O = 'O';
const char Board::TIE = '=';

bool Board::isValidMove(int square) {
    Coords coords = translateSquare(square);
    return (board[coords.x][coords.y] == ' ');
}

bool Board::isValidMove(Coords coords) {
    return (board[coords.x][coords.y] == ' ');
}

bool Board::isValidMove(int x, int y) { return (board[x][y] == ' '); }

Coords Board::translateSquare(int square) {
    switch (square) {
        case 1:
            return Coords{0, 0};
        case 2:
            return Coords{0, 1};
        case 3:
            return Coords{0, 2};
        case 4:
            return Coords{1, 0};
        case 5:
            return Coords{1, 1};
        case 6:
            return Coords{1, 2};
        case 7:
            return Coords{2, 0};
        case 8:
            return Coords{2, 1};
        case 9:
            return Coords{2, 2};
        default:
            std::cerr << "Invalid input: " + square << std::endl;
            return Coords{};
    }
}

int Board::translateSquare(Coords coords){
    return translateSquare(coords.x, coords.y);
}

int Board::translateSquare(int x, int y) {
    // Shift x 16 bits and OR it with y
    int combined = (x << 16) | y;

    switch (combined) {
        case (0 << 16) | 0:
            return 1;
        case (0 << 16) | 1:
            return 2;
        case (0 << 16) | 2:
            return 3;
        case (1 << 16) | 0:
            return 4;
        case (1 << 16) | 1:
            return 5;
        case (1 << 16) | 2:
            return 6;
        case (2 << 16) | 0:
            return 7;
        case (2 << 16) | 1:
            return 8;
        case (2 << 16) | 2:
            return 9;
        default:
            std::cerr << "Invalid input x: " + std::to_string(x) +
                             ", y: " + std::to_string(y)
                      << std::endl;
            return -1;
    }
}

bool Board::checkWin(char player) {
    // Check rows
    for (int row = 0; row < 3; ++row) {
        if (board[row][0] == player && board[row][1] == player &&
            board[row][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int col = 0; col < 3; ++col) {
        if (board[0][col] == player && board[1][col] == player &&
            board[2][col] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player &&
        board[2][2] == player) {
        return true;
    }

    if (board[0][2] == player && board[1][1] == player &&
        board[2][0] == player) {
        return true;
    }

    return false;
}

bool Board::checkTie() {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board[row][col] == ' ') {
                return false;  // Empty cell found, game is not a tie
            }
        }
    }
    return true;  // All cells are filled, game is a tie
}

bool Board::isOver() {
    if (checkWin(Board::X)) {
        return true;
    }

    if (checkWin(Board::O)) {
        return true;
    }

    if (checkTie()) {
        return true;
    }

    return false;
}

bool Board::makeMove(int square, char player) {
    if (!isValidMove(square)) return false;

    Coords coords = translateSquare(square);

    board[coords.x][coords.y] = player;
    return true;
}

bool Board::makeMove(int x, int y, char player) {
    return makeMove(translateSquare(x, y), player);
}

bool Board::makeMove(Coords coords, char player) {
    return makeMove(coords.x, coords.y, player);
}

void Board::printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 2) {
                std::cout << " " << std::string(1, board[i][j]) << std::endl;
            } else {
                std::cout << " " << std::string(1, board[i][j]) << " |";
            }
        }

        if (i != 2) {
            std::cout << "---+---+---" << std::endl;
        }
    }
    std::cout << std::endl;
}