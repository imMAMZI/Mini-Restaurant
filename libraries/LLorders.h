#ifndef LLSTUDESORDER_H
#define LLSTUDESORDER_H

#include "order.h"

// This class is a Linked List for all orders
class OrdersList {
public:
    Order* head;

    OrdersList();
    ~OrdersList();

    void addOrder(Order* newOrder);
    void printOrderList();
};

#endif