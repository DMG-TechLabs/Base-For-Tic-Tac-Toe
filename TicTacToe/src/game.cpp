#include "game.h"
#include "board.h"
#include "../Ansi-Text-Manipulation-Library/AnsiTextLibrary/src/ansi_lib.hpp"

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
using namespace TicTacToe;

char TicTacToe::start(Board board){
    AnsiTextLib::Text::clearScreen();

    char player = Board::X;
    while(!board.isOver()){
        board.printBoard();
        cout << "Playing: " << string(1, player) << endl;
        cout << endl;
        
        bool moveMade = board.makeMove(prompt(), player);
        if(moveMade) {
            (player == Board::X) ? player = Board::O : player = Board::X;
        }

        AnsiTextLib::Text::clearScreen();
    }
    board.printBoard();

    if(board.checkWin(Board::X)) {
        cout << "X won" << endl;
        return Board::X;
    }
    if(board.checkWin(Board::O)) {
        cout << "O won" << endl;
        return Board::O;
    }
    if(board.checkTie()){
        cout << "It's a tie" << endl;
        return Board::TIE;
    }

    return '!';
}

int TicTacToe::prompt(){
    string move;
    string numbers = "123456789";
    
    cout << "Enter move (1-9): ";
    getline(cin, move);

    if(move.length() > 1) {
        cerr << "Invalid input: " + move << endl;
        return prompt();
    }

    if(find(numbers.begin(), numbers.end(), move.at(0)) == numbers.end()){
        cerr << "Invalid input: " + move << endl;
        return prompt();
    }

    return stoi(move);
}