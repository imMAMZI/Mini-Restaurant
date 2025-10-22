#include "individualOrders.h"

IndividualOrders::IndividualOrders(std::string stdName, std::string stdID) {
    this->stdName = stdName;
    this->stdID = stdID;
}
IndividualOrders:: ~IndividualOrders() {}

void IndividualOrders::addItem(Item* item) {
    this->stdOrders.push_back(item);
}
void IndividualOrders::showItems() {
    double totalPrice = 0;
    for (int i = 0; i < stdOrders.size(); i++) {
        std::cout << termcolor::bright_grey << "Item name : " << termcolor::cyan << stdOrders[i]->getName()
        << termcolor::bright_grey << "     Item price : " << termcolor::cyan << stdOrders[i]->getPrice() << termcolor::reset << std::endl;
        totalPrice += stdOrders[i]->getPrice();
    }
    std::cout << termcolor::bright_blue << "Total : " << termcolor::reset << termcolor::bold << totalPrice << termcolor::reset << std::endl;
}

std::string IndividualOrders::getStdID() {
    return stdID;
}
std::string IndividualOrders::getStdName() {
    return stdName;
}
void IndividualOrders:: printStudentOrders() {
    std::cout << termcolor::bright_blue << "Student's name : " << termcolor::reset << termcolor::bold << this->getStdName() << termcolor::reset << std::endl;
    std::cout << termcolor::bright_blue << "Student's ID : " << termcolor::reset << termcolor::bold << this->getStdID() << termcolor::reset << std::endl;
    this->showItems();
    std::cout << termcolor::bright_red << "--------------------------" << termcolor::reset << std::endl;
}