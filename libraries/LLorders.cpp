#include "LLorders.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "termcolor.hpp"

OrdersList::OrdersList() : head(nullptr), tail(nullptr) {}
OrdersList::~OrdersList() = default;

void OrdersList::addOrder(Order* newOrder) {
    if (this->head == nullptr) {
        this->head = newOrder;
        this->tail = newOrder;
        newOrder->next = nullptr;
        newOrder->prev = nullptr;
    } else {
        newOrder->next = this->head;
        this->head->prev = newOrder;
        this->head = newOrder;
        this->head->prev= nullptr;
    }
    std::cout << termcolor::bright_green << "Order Number " << newOrder->thisOrderNumber << " added successfully" << termcolor::reset << std::endl;
}

void OrdersList::printOrderList() {
    Order* tmp = this->head;
    while (tmp != nullptr) {
        tmp->printOrder();
        tmp = tmp->next;
    }
}
void OrdersList:: writeIntoFile() {
    std::ofstream outfile("orders.csv");
    // No need to append: because every time we are writing all orders to the csv file from beginning

    if (!outfile.is_open()) {
        std::cout << termcolor::red << "ERROR : Can't open orders.csv to write" << termcolor::reset << std::endl;
        return;
    }

    Order* tmp = this->tail;
    while (tmp != nullptr) {
        outfile << tmp->getID() << "," << tmp->getStudentName() << "," << tmp->getOrderStatus() << ",";
        for (int i = 0; i < tmp->items.size(); i++) {
            outfile << tmp->items[i].getName() << "," << tmp->items[i].getPrice() << ",";
        }
        outfile << std::endl;
        tmp = tmp->prev;
    }
    outfile.close();
}
void OrdersList:: readFromFile(StudentOrders* stdorder) {
    std::ifstream newFile("orders.csv");
    if (!newFile.is_open()) {
        std::cout << termcolor::red << "ERROR : Can't open orders.csv to read" << termcolor::reset << std::endl;
    }

    std::string currentStdNum, currentStdName, currentItemName, tmpStatus, tmpPrice;
    int currentOrderStatus;

    std::string line;
    while (std::getline(newFile, line)) {
        std::istringstream ss(line);

        getline(ss, currentStdNum, ',');
        getline(ss, currentStdName, ',');
        getline(ss, tmpStatus, ',');
        currentOrderStatus = std::stoi(tmpStatus);

        getline(ss, currentItemName, ',');
        getline(ss, tmpPrice, ',');

        if (currentItemName == "Pizza") {
            Item* pizza = new Item("Pizza", 0, 10.23);
            Order* newOrder = new Order(currentStdNum, currentStdName, *(pizza), currentOrderStatus);
            this->addOrder(newOrder);
            if (stdorder->stdisAvailable(currentStdNum)) {
                stdorder->addtoStd(pizza, currentStdNum);
            } else {
                auto* tmp = new IndividualOrders(currentStdName, currentStdNum);
                stdorder->addStd(tmp);
                stdorder->addtoStd(pizza, currentStdNum);
            }
        } else if (currentItemName == "Burger") {
            Item* burger = new Item("Burger", 0, 7.44);
            Order* newOrder = new Order(currentStdNum, currentStdName, *(burger), currentOrderStatus);
            this->addOrder(newOrder);
            if (stdorder->stdisAvailable(currentStdNum)) {
                stdorder->addtoStd(burger, currentStdNum);
            } else {
                auto* tmp = new IndividualOrders(currentStdName, currentStdNum);
                stdorder->addStd(tmp);
                stdorder->addtoStd(burger, currentStdNum);
            }
        } else if (currentItemName == "Kabab") {
            Item* kabab = new Item("Kabab", 0, 15);
            Order* newOrder = new Order(currentStdNum, currentStdName, *(kabab), currentOrderStatus);
            this->addOrder(newOrder);
            if (stdorder->stdisAvailable(currentStdNum)) {
                stdorder->addtoStd(kabab, currentStdNum);
            } else {
                auto* tmp = new IndividualOrders(currentStdName, currentStdNum);
                stdorder->addStd(tmp);
                stdorder->addtoStd(kabab, currentStdNum);
            }
        } else if (currentItemName == "Coffee") {
            Item* coffee = new Item("Coffee", 1, 2.5);
            Order* newOrder = new Order(currentStdNum, currentStdName, *(coffee), currentOrderStatus);
            this->addOrder(newOrder);
            if (stdorder->stdisAvailable(currentStdNum)) {
                stdorder->addtoStd(coffee, currentStdNum);
            } else {
                auto* tmp = new IndividualOrders(currentStdName, currentStdNum);
                stdorder->addStd(tmp);
                stdorder->addtoStd(coffee, currentStdNum);
            }
        } else if (currentItemName == "Cola") {
            Item* cola = new Item("Cola", 1, 1.5);
            Order* newOrder = new Order(currentStdNum, currentStdName, *(cola), currentOrderStatus);
            this->addOrder(newOrder);
            if (stdorder->stdisAvailable(currentStdNum)) {
                stdorder->addtoStd(cola, currentStdNum);
            } else {
                auto* tmp = new IndividualOrders(currentStdName, currentStdNum);
                stdorder->addStd(tmp);
                stdorder->addtoStd(cola, currentStdNum);
            }
        } else if (currentItemName == "Water") {
            Item* water = new Item("Water", 1, 0.1);
            Order* newOrder = new Order(currentStdNum, currentStdName, *(water), currentOrderStatus);
            this->addOrder(newOrder);
            if (stdorder->stdisAvailable(currentStdNum)) {
                stdorder->addtoStd(water, currentStdNum);
            } else {
                auto* tmp = new IndividualOrders(currentStdName, currentStdNum);
                stdorder->addStd(tmp);
                stdorder->addtoStd(water, currentStdNum);
            }
        } else if (currentItemName == "Soup") {
            Item* soup = new Item("Soup", 2, 3.43);
            Order* newOrder = new Order(currentStdNum, currentStdName, *(soup), currentOrderStatus);
            this->addOrder(newOrder);
            if (stdorder->stdisAvailable(currentStdNum)) {
                stdorder->addtoStd(soup, currentStdNum);
            } else {
                auto* tmp = new IndividualOrders(currentStdName, currentStdNum);
                stdorder->addStd(tmp);
                stdorder->addtoStd(soup, currentStdNum);
            }
        } else if (currentItemName == "Jelly") {
            Item* jelly = new Item("Jelly", 2, 1.43);
            Order* newOrder = new Order(currentStdNum, currentStdName, *(jelly), currentOrderStatus);
            this->addOrder(newOrder);
            if (stdorder->stdisAvailable(currentStdNum)) {
                stdorder->addtoStd(jelly, currentStdNum);
            } else {
                auto* tmp = new IndividualOrders(currentStdName, currentStdNum);
                stdorder->addStd(tmp);
                stdorder->addtoStd(jelly, currentStdNum);
            }
        } else if (currentItemName == "FruitDish") {
            Item* fruitDish = new Item("FruitDish", 2, 3.66);
            Order* newOrder = new Order(currentStdNum, currentStdName, *(fruitDish), currentOrderStatus);
            this->addOrder(newOrder);
            if (stdorder->stdisAvailable(currentStdNum)) {
                stdorder->addtoStd(fruitDish, currentStdNum);
            } else {
                auto* tmp = new IndividualOrders(currentStdName, currentStdNum);
                stdorder->addStd(tmp);
                stdorder->addtoStd(fruitDish, currentStdNum);
            }
        }

        while (getline(ss, currentItemName, ',') && getline(ss, tmpPrice, ',')) {

            if (currentItemName == "Pizza") {
                Item* pizza = new Item("Pizza", 0, 10.23);
                this->head->addToOrder(*(pizza));
                stdorder->addtoStd(pizza, currentStdNum);
            } else if (currentItemName == "Burger") {
                Item* burger = new Item("Burger", 0, 7.44);
                this->head->addToOrder(*(burger));
                stdorder->addtoStd(burger, currentStdNum);
            } else if (currentItemName == "Kabab") {
                Item* kabab = new Item("Kabab", 0, 15);
                this->head->addToOrder(*(kabab));
                stdorder->addtoStd(kabab, currentStdNum);
            } else if (currentItemName == "Coffee") {
                Item* coffee = new Item("Coffee", 1, 2.5);
                this->head->addToOrder(*(coffee));
                stdorder->addtoStd(coffee, currentStdNum);
            } else if (currentItemName == "Cola") {
                Item* cola = new Item("Cola", 1, 1.5);
                this->head->addToOrder(*(cola));
                stdorder->addtoStd(cola, currentStdNum);
            } else if (currentItemName == "Water") {
                Item* water = new Item("Water", 2, 0.1);
                this->head->addToOrder(*(water));
                stdorder->addtoStd(water, currentStdNum);
            } else if (currentItemName == "Soup") {
                Item* soup = new Item("Soup", 2, 3.43);
                this->head->addToOrder(*(soup));
                stdorder->addtoStd(soup, currentStdNum);
            } else if (currentItemName == "Jelly") {
                Item* jelly = new Item("Jelly", 2, 1.43);
                this->head->addToOrder(*(jelly));
                stdorder->addtoStd(jelly, currentStdNum);
            } else if (currentItemName == "FruitDish") {
                Item* fruitDish = new Item("FruitDish", 2, 3.66);
                this->head->addToOrder(*(fruitDish));
                stdorder->addtoStd(fruitDish, currentStdNum);
            }
        }
    }
    newFile.close();
}