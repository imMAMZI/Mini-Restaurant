#ifndef individualOrders_h
#define individualOrders_h

#include <vector>

#include <iostream>
#include "item.h"
#include "termcolor.hpp"

class IndividualOrders {
private:
    std::string stdName;
    std::string stdID;
    std::vector<Item*> stdOrders;

public:
    IndividualOrders* next;
    IndividualOrders(std::string stdName, std::string stdID);
    ~IndividualOrders();

    void addItem(Item* item);
    void showItems();

    std::string getStdID();
    std::string getStdName();
};

#endif