#include "studentorders.h"

StudentOrders::StudentOrders(): head(nullptr) {}
StudentOrders:: ~StudentOrders() {}

void StudentOrders:: addOrder(Order* newOrder) {
    // make sure that you make 2 instances of the given order :
    // one for the Orderlist linkedlist
    //  another for this linkedlist (do not use one instance)
    if (this->head == nullptr) {
        this->head = newOrder;
        newOrder->next = nullptr;
    } else {
        this->head->next = newOrder;
        newOrder->next = nullptr;
        this->head = newOrder;
    }
}
void StudentOrders:: printOrderList() {
    Order* tmp = this->head;
    while (tmp != nullptr) {
        tmp->printOrder();
        tmp = tmp->next;
    }
}