#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <vector>

#include "item.h"

class Order {
private:
    std:: string stdID;
    std:: string stdName;
    int orderStatus; // 0: Pending - 1: Received - 2: Canceled
    double totalPrice;
public:
    int thisOrderNumber;
    std::vector<Item> items;
    static int orderNumber;
    Order* next;
    Order* next_std;

    Order(std::string stdNum, std::string stdName, Item& stdItem);
    ~Order();

    bool addToOrder(Item& newOrder);
    void printOrder();
    bool changeOrderStatus(int newStatus);
    bool deleteFromOrder(std::string itemName);
    std::string getID();
    bool getOrderStatus();
    std::string getStudentName();
};

#endif