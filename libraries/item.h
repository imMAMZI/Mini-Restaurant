#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
private:
    std::string name;
    int type; // 0: Food - 1: Drink - 2: Appetizer
    double price;
public:
    Item(std::string name, int type, double price);
    ~Item();

    bool changeItemPrice(double newPrice);
    double getPrice();
    std::string getName();
};

#endif