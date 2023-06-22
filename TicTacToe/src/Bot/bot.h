#pragma once

#include "../utils/game_utils.h"

using namespace Game_Utils;

class Bot{
    bool moveTo(int cell_num, vector<string> accepted_moves, Board *board, string turn_of);
};