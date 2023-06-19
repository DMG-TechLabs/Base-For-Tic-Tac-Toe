#pragma once

#include "../game_structure/board.h"
#include "prompt.h"

#include <iostream>
#include <vector>
#include <string>

using namespace Utils;
using namespace std;

namespace Game_Utils{
    bool check_result(Board *board);
    bool turn(string message, Response response, vector<string> accepted_input, Board *board, string turn_of);
};