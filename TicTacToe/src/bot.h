#pragma once

#include "board.h"

namespace TicTacToe{
    class Bot {
        public:
            virtual ~Bot(){}
            Bot(){}
            virtual int generateMove(Board b) = 0;
    };
} // namespace TicTacToe
