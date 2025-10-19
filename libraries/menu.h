#ifndef MENU_H
#define MENU_H

#include "item.h"
#include <iostream>
#include <vector>
#include "termcolor.hpp"

class Menu {
public:
    Item* pizza = new Item("Pizza", 0, 10.23);
    Item* burger = new Item("Burger", 0, 7.44);
    Item* kabab = new Item("Kabab", 0, 15);
    Item* coffee = new Item("Coffee", 1, 2.5);
    Item* cola = new Item("Cola", 1, 1.5);
    Item* water = new Item("Water", 1, 0.1);
    Item* soup = new Item("Soup", 2, 3.43);
    Item* jelly = new Item("Jelly", 2, 1.43);
    Item* fruitDish = new Item("FruitDish", 2, 3.66);

    std::vector<Item*> ItemsOnTheMenu = {pizza, burger, kabab, coffee, cola, water, soup, jelly, fruitDish};
    Menu();
    ~Menu();

    void showMenu();

};

#endif