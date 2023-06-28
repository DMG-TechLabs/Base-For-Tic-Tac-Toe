#include "menu.h"

#include <iostream>
#include <string>
#include <regex>
#include "../utils/game_utils.h"

#ifdef _WIN32
    #include <windows.h>
    #include <thread>
    #include <chrono>

    using namespace std;
#else
    #include <unistd.h>
#endif

using namespace AnsiTextLib;
using namespace Menu;
using namespace Game_Utils;
using namespace Utils;

void handleMenuOptions(int selectedItem){
    Board *board = new Board();

    switch (selectedItem){
        case 0:
            Game_Utils::start(board);

            Utils::println("\n\nPress enter to return to menu...");
            cin.get();
            break;
        case 1:
            Utils::println("Quiting game...");
            #ifdef _WIN32
                std::this_thread::sleep_for(chrono::seconds(1));
            #else
                sleep(1);
            #endif
            std::exit(0);
    }

    Menu::mainMenu();
}

void Menu::mainMenu(){
    AnsiTextLib::menu("Tic Tac Toe", 4, {"Play", "Exit"}, &handleMenuOptions);
}