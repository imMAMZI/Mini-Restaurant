#include "order.h"
#include "termcolor.hpp"

Order:: Order(std::string stdNum, std::string stdName, Item& stdItem): next(nullptr), next_std(nullptr) {
    this->orderNumber++;
    this->stdID = stdNum;
    this->stdName = stdName;
    this->orderStatus = false;
    this->items.push_back(stdItem);
    this->totalPrice = stdItem.getPrice();
}
Order:: ~Order() {}

bool Order:: addToOrder(Item& newOrder) {
    this->items.push_back(newOrder);
    this->totalPrice += newOrder.getPrice();
    return true;
}
void Order:: printOrder() {
    std::cout << termcolor::bold << "Customer information : " << termcolor::reset << std::endl
    << termcolor::bright_blue << "   Student ID : " << termcolor::reset << stdID << std::endl
    << termcolor::bright_blue << "   Student Name : " << termcolor::reset << stdName << std::endl
    << termcolor::bold << "Order Information : " << termcolor::reset << std::endl;
    for (int i = 0; i < this->items.size(); i++) {
        std::cout << "   " << termcolor::bright_blue << items.at(i).getName()
        << "      " << termcolor::bright_red << items.at(i).getPrice() << termcolor::reset << std::endl;
    }
}
bool Order:: changeOrderStatus(int newStatus) {
    if (this->orderStatus == 2) {
        std::cout << termcolor::red << "Order already canceled, please make another order" <<
        termcolor::reset << std::endl;
        return false;
    }
    if (orderStatus == newStatus) {
        return false;
    }
    this->orderStatus = newStatus;
    return true;
}
bool Order:: deleteFromOrder(std::string itemName) {
    if (this->orderStatus != 0) {
        std::cout << termcolor::red << termcolor::bold << "Failed" << termcolor::reset << std::endl
        << termcolor::red << "Order already received or canceled" << termcolor::reset << std::endl;
        return false;
    } else if (this->items.size() <= 1) {
        std::cout << termcolor::red << termcolor::bold << "Failed" << termcolor::reset << std::endl
        << "Order will be empty after removing this item - Inaccessible" << termcolor::reset << std::endl;
        return false;
    } else {
        for (int i = 0; i < this->items.size(); i++) {
            if (items.at(i).getName() == itemName) {
                items.erase(items.begin() + i);
                this->totalPrice -= this->items.at(i).getPrice();
                return true;
            }
        }
            std::cout << termcolor::red << termcolor::bold << "Failed" << termcolor::reset << std::endl
            << termcolor::red << "Item not found" << termcolor::reset << std::endl;
            return false;
    }
}
std::string Order::getID() {
    return this->stdID;
}

