#include "LLorders.h"

OrdersList::OrdersList(): head(nullptr) {}
OrdersList:: ~OrdersList() {}

void OrdersList:: addOrder(Order* newOrder) {
    if (this->head == nullptr) {
        this->head = newOrder;
        newOrder->next = nullptr;
    } else {
        this->head->next = newOrder;
        newOrder->next = nullptr;
        this->head = newOrder;
    }
}
void OrdersList:: printOrderList() {
    Order* tmp = this->head;
    while (tmp != nullptr) {
        tmp->printOrder();
        tmp = tmp->next;
    }
}
