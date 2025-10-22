#include "order.h"
#include "termcolor.hpp"

Order:: Order(std::string stdNum, std::string stdName, Item& stdItem, int status): next(nullptr), prev(nullptr) {
    this->orderNumber++;
    this->stdID = stdNum;
    this->stdName = stdName;
    this->orderStatus = false;
    this->items.push_back(stdItem);
    this->totalPrice = stdItem.getPrice();
    this->thisOrderNumber = orderNumber;
    this->orderStatus = status;
}
Order:: ~Order() {}

bool Order:: addToOrder(Item& newOrder) {
    this->items.push_back(newOrder);
    this->totalPrice += newOrder.getPrice();
    std::cout << termcolor::bright_green << "Added item to the order successfully" << termcolor::reset << std::endl;
    return true;
}
void Order:: printOrder() {
    std::cout << termcolor::bold << "Customer information : " << termcolor::reset << std::endl
    << termcolor::bright_blue << "   Student 6ID : " << termcolor::reset << termcolor::bold << stdID << termcolor::reset << std::endl
    << termcolor::bright_blue << "   Student Name : " << termcolor::reset << termcolor::bold << stdName << termcolor::reset << std::endl
    << termcolor::bold << "Order Information : " << termcolor::reset << std::endl;
    for (int i = 0; i < this->items.size(); i++) {
        std::cout << "   " << termcolor::bright_blue << items.at(i).getName()
        << "   " << termcolor::bright_red << items.at(i).getPrice() << termcolor::reset << std::endl;
    }
    std::cout << "Order number : " << this->thisOrderNumber << std::endl;
    if (this->orderStatus == 0) {
        std::cout << std::endl << termcolor::bright_grey << "Order status : " << termcolor::reset << termcolor::bold
        << "Pending" << termcolor::reset << std::endl;
    } else if (this->orderStatus == 1) {
        std::cout << termcolor::bright_grey << std::endl << "Order status : " << termcolor::green << termcolor::bold
        << "Received" << termcolor::reset << std::endl;
    } else if (this->orderStatus == 2) {
        std::cout << termcolor::bright_grey << std::endl << "Order status : " << termcolor::red << termcolor::bold
        << "Canceled" << termcolor::reset << std::endl;
    }
    std::cout << termcolor::bright_grey << "Total Price : " << termcolor::red << termcolor::bold
    << this->totalPrice << termcolor::reset << std::endl;
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
bool Order:: deleteFromOrder(std::string itemName, bool status) {
    if (this->orderStatus != 0) {
        std::cout << termcolor::red << termcolor::bold << "Failed" << termcolor::reset << std::endl
        << termcolor::red << "Order already received or canceled" << termcolor::reset << std::endl;
        return false;
    } else if (this->items.size() <= 1 && !status) {
        std::cout << termcolor::red << termcolor::bold << "Failed" << termcolor::reset << std::endl
        << "Order will be empty after removing this item - Inaccessible" << termcolor::reset << std::endl;
        return false;
    } else {
        for (int i = 0; i < this->items.size(); i++) {
            if (items.at(i).getName() == itemName) {
                this->totalPrice -= this->items.at(i).getPrice();
                items.erase(items.begin() + i);
                std::cout << termcolor::bright_green << "Deleted the item from order successfully" << termcolor::reset << std::endl;
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
int Order::getOrderStatus() {
    return this->orderStatus;
}
double Order:: getTotalPrice() {
    return this->totalPrice;
}
std::string Order::getStudentName() {
    return this->stdName;
}

