#ifndef LLSTUDESORDER_H
#define LLSTUDESORDER_H

#include "order.h"
#include "studentorders.h"
#include "individualOrders.h"

// This class is a Linked List for all orders
class OrdersList {
public:
    Order* head;
    Order* tail;

    OrdersList();
    ~OrdersList();

    void addOrder(Order* newOrder);
    void printOrderList();
    void writeIntoFile();
    void readFromFile(StudentOrders* stdorder);
};

#endif