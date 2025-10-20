#include "studentorders.h"

#include "termcolor.hpp"

StudentOrders::StudentOrders(): head(nullptr) {}
StudentOrders:: ~StudentOrders() {}

void StudentOrders:: addStd(IndividualOrders* newStd) {
    // make sure that you make 2 instances of the given order :
    // one for the Orderlist linkedlist
    //  another for this linkedlist (do not use one instance)
    if (this->head == nullptr) {
        this->head = newStd;
        newStd->next = nullptr;
    } else {
        newStd->next = this->head;
        this->head = newStd;
    }
    std::cout << termcolor::bright_green << "Added student successfully" << termcolor::reset << std::endl;
}
void StudentOrders::addtoStd(Item* newItem, std::string stdID) {
    IndividualOrders* tmp = this->head;
    while (tmp != nullptr) {
        if (tmp->getStdID() == stdID) {
            tmp->addItem(newItem);
            std::cout << termcolor::bright_green << "Added " << newItem->getName() << " to the student successfully"
            << termcolor::reset << std::endl;
         }
        tmp = tmp->next;
    }
}
bool StudentOrders::stdisAvailable(std::string ID) {
    IndividualOrders* tmp = this->head;
    while (tmp != nullptr) {
        if (tmp->getStdID() == ID) {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}