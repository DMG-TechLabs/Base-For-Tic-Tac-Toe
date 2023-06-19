#pragma once

#include <iostream>

using namespace std;

class Board {
    public:
        string space[3][3] = {{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}};

        Board(){};
        ~Board(){};

        void printBoard();
        void printHelpingBoard();
};
