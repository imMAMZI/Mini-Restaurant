#include "menu.h"

void Menu:: showMenu() {
    std::cout << termcolor::blue << termcolor::bold << "FOODS : " << termcolor::reset << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << termcolor::bright_grey << "   " << i+1 << ". Item name : " << termcolor::reset << termcolor::bold
        << this->ItemsOnTheMenu.at(i)->getName() << "      " << termcolor::reset << termcolor::bright_grey
        << "Item price : " << termcolor::reset << termcolor::bold << this->ItemsOnTheMenu.at(i)->getPrice() << std::endl;
    }
    std::cout << termcolor::blue << termcolor::bold << "Drinks : " << termcolor::reset << std::endl;
    for (int i = 3; i < 6; i++) {
        std::cout << termcolor::bright_grey << "   " << i+1 << ". Item name : " << termcolor::reset << termcolor::bold
        << this->ItemsOnTheMenu.at(i)->getName() << "      " << termcolor::reset << termcolor::bright_grey
        << "Item price : " << termcolor::reset << termcolor::bold << this->ItemsOnTheMenu.at(i)->getPrice() << std::endl;
    }
    std::cout << termcolor::blue << termcolor::bold << "Appetizers : " << termcolor::reset << std::endl;
    for (int i = 6; i < 9; i++) {
        std::cout << termcolor::bright_grey << "   " << i+1 << ". Item name : " << termcolor::reset << termcolor::bold
        << this->ItemsOnTheMenu.at(i)->getName() << "      " << termcolor::reset << termcolor::bright_grey
        << "Item price : " << termcolor::reset << termcolor::bold << this->ItemsOnTheMenu.at(i)->getPrice()
        << termcolor::reset << std::endl;
    }
}
Menu::Menu() {}
Menu::~Menu() {}

