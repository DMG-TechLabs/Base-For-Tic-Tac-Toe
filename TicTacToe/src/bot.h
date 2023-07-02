#pragma once

#include "board.h"

namespace TicTacToe{
    class Bot {
        public:
            virtual ~Bot(){}
            Bot(){}
            virtual int generateMove(char move_for, Board b) = 0;
    };
} // namespace TicTacToe
