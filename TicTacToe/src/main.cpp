#include "./game_structure/board.h"
#include "./utils/game_utils.h"

using namespace Utils;
using namespace Game_Utils;

void start(Board *board){
    Prompt prompt;
    prompt.accepted_moves = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

    bool flag = false, result;

    //board->printHelpingBoard();

    board->printBoard();

    do{
        flag = Utils::prompt("X's turn", prompt.accepted_moves, board, "x");
        while(!flag){
            flag = Utils::prompt("X's turn", prompt.accepted_moves, board, "x");
        }

        result = Game_Utils::checkResult(board);
        if(result == true){
            break;
        }

        flag = Utils::prompt("O's turn", prompt.accepted_moves, board, "o");
        while(!flag){
            flag = Utils::prompt("O's turn", prompt.accepted_moves, board, "o");
        }

        result = Game_Utils::checkResult(board);
    } while(!result);

}

int main() {
    Board *board = new Board();

    start(board);

    return 0;
}