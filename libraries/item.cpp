#include "item.h"

Item::Item(std::string name, int type, double price) {
    this->name = name;
    this->type = type;
    this->price = price;
}
Item:: ~Item() {}

bool Item:: changeItemPrice(double newPrice) {
    if (newPrice < 0 || newPrice > 20) {
        return false;
    }
    this->price = newPrice;
    return true;
}
double Item:: getPrice() const {
    return this->price;
}
std::string Item::getName() const {
    return this->name;
}
int Item::getType() const {
    return this->type;
}
