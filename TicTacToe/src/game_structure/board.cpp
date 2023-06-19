#include "board.h"

using namespace std;

void Board::printBoard(){
    cout <<"     |     |     \n";
    cout <<"  "<< space[0][0] <<"  |  " <<space[0][1] <<"  |  "<< space[0][2] <<"  \n";
    cout <<"_____|_____|_____\n";
    cout <<"     |     |     \n";
    cout <<"  "<< space[1][0] <<"  |  "<< space[1][1] <<"  |  "<< space[1][2] <<"  \n";
    cout <<"_____|_____|_____\n";
    cout <<"     |     |     \n";
    cout <<"  "<< space[2][0] <<"  |  "<< space[2][1] <<"  |  "<< space[2][2] <<"  \n";
    cout <<"     |     |     \n\n";
}

void Board::printHelpingBoard(){
    cout <<"\n  Helping Board  \n";
    cout <<"*****************\n";
    cout <<"     |     |     \n";
    cout <<"  1  |  2  |  3  \n";
    cout <<"_____|_____|_____\n";
    cout <<"     |     |     \n";
    cout <<"  4  |  5  |  6  \n";
    cout <<"_____|_____|_____\n";
    cout <<"     |     |     \n";
    cout <<"  7  |  8  |  9  \n";
    cout <<"     |     |     \n";
    cout <<"*****************\n\n";
}