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
    for (int i = 0; i < stdOrders.size(); i++) {
        std::cout << "Item name : " << stdOrders[i]->getName()
        << "     Item price : " << stdOrders[i]->getPrice() << std::endl;
    }
}

std::string IndividualOrders::getStdID() {
    return stdID;
}
std::string IndividualOrders::getStdName() {
    return stdName;
}


