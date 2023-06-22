#include "bot.h"
#include "../../Ansi-Text-Manipulation-Library/AnsiTextLibrary/src/ansi_lib.hpp"

bool Bot::moveTo(int cell_num, vector<string> accepted_moves, Board *board, string turn_of){
    if(to_string(cell_num) == accepted_moves.at(0) && board->space[0][0] == " "){
        board->space[0][0] = turn_of;
        AnsiTextLib::Text::clearScreen();
        board->printBoard();
        return true;
    } else if(to_string(cell_num) == accepted_moves.at(1) && board->space[0][1] == " "){
        board->space[0][1] = turn_of;
        AnsiTextLib::Text::clearScreen();
        board->printBoard();
        return true;
    } else if(to_string(cell_num) == accepted_moves.at(2) && board->space[0][2] == " "){
        board->space[0][2] = turn_of;
        AnsiTextLib::Text::clearScreen();
        board->printBoard();
        return true;
    } else if(to_string(cell_num) == accepted_moves.at(3) && board->space[1][0] == " "){
        board->space[1][0] = turn_of;
        AnsiTextLib::Text::clearScreen();
        board->printBoard();
        return true;
    } else if(to_string(cell_num) == accepted_moves.at(4) && board->space[1][1] == " "){
        board->space[1][1] = turn_of;
        AnsiTextLib::Text::clearScreen();
        board->printBoard();
        return true;
    } else if(to_string(cell_num) == accepted_moves.at(5) && board->space[1][2] == " "){
        board->space[1][2] = turn_of;
        AnsiTextLib::Text::clearScreen();
        board->printBoard();
        return true;
    } else if(to_string(cell_num) == accepted_moves.at(6) && board->space[2][0] == " "){
        board->space[2][0] = turn_of;
        AnsiTextLib::Text::clearScreen();
        board->printBoard();
        return true;
    } else if(to_string(cell_num) == accepted_moves.at(7) && board->space[2][1] == " "){
        board->space[2][1] = turn_of;
        AnsiTextLib::Text::clearScreen();
        board->printBoard();
        return true;
    } else if(to_string(cell_num) == accepted_moves.at(8) && board->space[2][2] == " "){
        board->space[2][2] = turn_of;
        AnsiTextLib::Text::clearScreen();
        board->printBoard();
        return true;
    }

    return false;
}