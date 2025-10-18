#ifndef STUDENTORDERS_H
#define STUDENTORDERS_H

#include "order.h"

// this is a linked list for each student's orders
class StudentOrders {
public:
    Order* head;

    StudentOrders();
    ~StudentOrders();

    void addOrder(Order* newOrder);
    void printOrderList();
};

#endif