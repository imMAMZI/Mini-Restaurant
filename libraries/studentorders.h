#ifndef STUDENTORDERS_H
#define STUDENTORDERS_H

#include "individualOrders.h"

// this is a linked list for each student's orders
class StudentOrders {
public:
    IndividualOrders* head;

    StudentOrders();
    ~StudentOrders();

    void addStd(IndividualOrders* newStd);
    void addtoStd(Item* newItem, std::string stdID);
    bool stdisAvailable(std::string ID);
};

#endif