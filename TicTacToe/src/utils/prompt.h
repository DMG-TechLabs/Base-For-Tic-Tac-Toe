#pragma once

#include "../game_structure/board.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace Utils{
    struct Prompt{
        string message;
        vector<string> accepted_moves = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    };

    struct Response{
        string input;
    };

    bool prompt(string message, vector<string> accepted_moves, Board *board, string turn_of);

    void println(string message);
    void print(string message);
}
