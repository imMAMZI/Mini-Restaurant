#include "LLorders.h"

OrdersList::OrdersList(): head(nullptr) {}
OrdersList:: ~OrdersList() {}

void OrdersList:: addOrder(Order* newOrder) {
    if (this->head == nullptr) {
        this->head = newOrder;
        newOrder->next = nullptr;
    } else {
        newOrder->next = this->head;
        this->head = newOrder;
    }
    std::cout << "Order added successfully" << std::endl;
}
void OrdersList:: printOrderList() {
    Order* tmp = this->head;
    while (tmp != nullptr) {
        tmp->printOrder();
        tmp = tmp->next;
    }
}