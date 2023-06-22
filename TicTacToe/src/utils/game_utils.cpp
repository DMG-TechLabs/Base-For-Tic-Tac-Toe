#include "game_utils.h"
#include "../../Ansi-Text-Manipulation-Library/AnsiTextLibrary/src/ansi_lib.hpp"

#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
    #include <thread>
    #include <chrono>

    using namespace std;
#else
    #include <unistd.h>
#endif

using namespace Game_Utils;
using namespace Utils;

bool Game_Utils::checkResult(Board *board){
    if(checkWin(board, "x")){
        println("Player with x wins!");
        return true;
    } else if(checkWin(board, "o")){
        println("Player with o wins!");
        return true;
    } else if(checkTie(board)){
        println("The game is tie!");
        return true;
    }

    return false;
}

bool Game_Utils::checkWin(Board *board, string turn_of){
    if(board->space[0][0] == turn_of && board->space[1][1] == turn_of && board->space[2][2] == turn_of) return true;

    if(board->space[0][0] == turn_of && board->space[0][1] == turn_of && board->space[0][2] == turn_of) return true;

    if(board->space[0][0] == turn_of && board->space[1][0] == turn_of && board->space[2][0] == turn_of) return true;

    if(board->space[0][2] == turn_of && board->space[1][1] == turn_of && board->space[2][0] == turn_of) return true;
    
    if(board->space[0][2] == turn_of && board->space[1][2] == turn_of && board->space[2][2] == turn_of) return true;
    
    if(board->space[2][2] == turn_of && board->space[2][1] == turn_of && board->space[2][0] == turn_of) return true;
    
    if(board->space[0][1] == turn_of && board->space[1][1] == turn_of && board->space[2][1] == turn_of) return true;
    
    if(board->space[1][0] == turn_of && board->space[1][1] == turn_of && board->space[1][2] == turn_of) return true;

    return false;
}

bool Game_Utils::checkTie(Board *board){
    if(board->space[0][0] != " " && board->space[0][1] != " " && board->space[0][2] != " " 
        && board->space[1][0] != " " && board->space[1][1] != " "
        && board->space[1][2] != " " && board->space[2][0] != " " 
        && board->space[2][1] != " " && board->space[2][2] != " "){
        return true;
    }

    return false;
}

bool Game_Utils::turn(string message, Response response, vector<string> accepted_moves, Board *board, string turn_of){
    println(message);
    print("> ");
    
    getline(cin, response.input);
    while(response.input != accepted_moves.at(0) && response.input != accepted_moves.at(1) && response.input != accepted_moves.at(2) && response.input != accepted_moves.at(3)
        && response.input != accepted_moves.at(4) && response.input != accepted_moves.at(5) && response.input != accepted_moves.at(6) && response.input != accepted_moves.at(7)
        && response.input != accepted_moves.at(8)){
        println("***Invalid Input***");
        #ifdef _WIN32
            std::this_thread::sleep_for(chrono::seconds(1));
        #else
            sleep(1);
        #endif
        AnsiTextLib::Text::clearScreen();
        board->printBoard();
        println(message);
        print("> ");
        getline(cin, response.input);
    }

    if(response.input == accepted_moves.at(0) && board->space[0][0] == " "){
        board->space[0][0] = turn_of;
        AnsiTextLib::Text::clearScreen();
        board->printBoard();
        return true;
    } else if(response.input == accepted_moves.at(1) && board->space[0][1] == " "){
        board->space[0][1] = turn_of;
        AnsiTextLib::Text::clearScreen();
        board->printBoard();
        return true;
    } else if(response.input == accepted_moves.at(2) && board->space[0][2] == " "){
        board->space[0][2] = turn_of;
        AnsiTextLib::Text::clearScreen();
        board->printBoard();
        return true;
    } else if(response.input == accepted_moves.at(3) && board->space[1][0] == " "){
        board->space[1][0] = turn_of;
        AnsiTextLib::Text::clearScreen();
        board->printBoard();
        return true;
    } else if(response.input == accepted_moves.at(4) && board->space[1][1] == " "){
        board->space[1][1] = turn_of;
        AnsiTextLib::Text::clearScreen();
        board->printBoard();
        return true;
    } else if(response.input == accepted_moves.at(5) && board->space[1][2] == " "){
        board->space[1][2] = turn_of;
        AnsiTextLib::Text::clearScreen();
        board->printBoard();
        return true;
    } else if(response.input == accepted_moves.at(6) && board->space[2][0] == " "){
        board->space[2][0] = turn_of;
        AnsiTextLib::Text::clearScreen();
        board->printBoard();
        return true;
    } else if(response.input == accepted_moves.at(7) && board->space[2][1] == " "){
        board->space[2][1] = turn_of;
        AnsiTextLib::Text::clearScreen();
        board->printBoard();
        return true;
    } else if(response.input == accepted_moves.at(8) && board->space[2][2] == " "){
        board->space[2][2] = turn_of;
        AnsiTextLib::Text::clearScreen();
        board->printBoard();
        return true;
    }

    println("***You can't do that here***");
    #ifdef _WIN32
        std::this_thread::sleep_for(chrono::seconds(1));moves
    #else
        sleep(1);
    #endif
    AnsiTextLib::Text::clearScreen();
    board->printBoard();
    return false;
}
