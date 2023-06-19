#pragma once


namespace TicTacToe{

    struct Coords{
        int x;
        int y;
    };

    class Board{
        public:
            static const char X;
            static const char O;
            static const char TIE;

            char board[3][3] = {
                {' ', ' ', ' '},
                {' ', ' ', ' '},
                {' ', ' ', ' '}
            };

            bool isOver();
            bool makeMove(int square, char player);
            bool makeMove(int x, int y, char player);
            bool makeMove(Coords coords, char player);

            bool checkWin(char player);
            bool checkTie();

            void printBoard();

            bool isValidMove(int square);
            bool isValidMove(int x, int y);
            bool isValidMove(Coords coords);
            int translateSquare(int x, int y);
            int translateSquare(Coords coords);
            Coords translateSquare(int square);
    };


};