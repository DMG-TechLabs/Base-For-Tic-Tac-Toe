#include "menu.h"

#include "../utils/prompt.h"

using namespace AnsiTextLib;
using namespace Menu;
using namespace Utils;

void handleMenuOptions(int selectedItem){
    switch (selectedItem){
        case 0:
            return;
        case 1:
            Utils::println("Quiting game...");
            std::exit(0);
    }
}

void Menu::mainMenu(){
    AnsiTextLib::menu("Tic Tac Toe", 4, {"Play", "Exit"}, &handleMenuOptions);
}