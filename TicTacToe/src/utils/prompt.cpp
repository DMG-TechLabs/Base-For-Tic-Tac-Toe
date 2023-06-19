#include "game_utils.h"
#include "../../Ansi-Text-Manipulation-Library/AnsiTextLibrary/src/ansi_lib.hpp"

using namespace Utils;

bool Utils::prompt(string message, vector<string> accepted_input, Board *board, string turn_of){
    Response response;
    
    if(turn_of == "x") return Game_Utils::turn(message, response, accepted_input, board, turn_of);

    else if(turn_of == "o") return Game_Utils::turn(message, response, accepted_input, board, turn_of);

    return false;
}

void Utils::println(string message){
    cout << message << endl;
}

void Utils::print(string message) {
    cout << message; 
}