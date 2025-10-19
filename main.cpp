#include <iostream>

#include "libraries/menu.h"
#include "libraries/order.h"
#include <sstream>
#include <ext/concurrence.h>
#include "libraries/LLorders.h"
#include "libraries/studentorders.h"

void showCommands();
bool validateID(std::string stdID);
bool validateItem(int stdItem);

int Order::orderNumber = 0;
int main () {
    auto* orderlist = new OrdersList();
    auto* stdorder = new StudentOrders();
    Menu* menu = new Menu();

    std::cout << termcolor::bold << "Welcome to this restaurant!" << termcolor::bold << termcolor::green
    << std::endl << "Where all the items are less than 20 dollars!!" << "\n\n";

    std::cout << std::endl << termcolor::bold << termcolor::green << "Commands(type the number specified for each) : "
    << termcolor::reset << std::endl;

    int input = 10;
    std::string line;
    std::string currentName, currentID, currentItem;
    int currentItemINT;
    Order* order = nullptr;

    while (input != 0) {
        showCommands();
        std::cin >> input;
        switch (input) {
            case 1:
                menu->showMenu();
                break;
            case 2: {
                menu->showMenu();
                std::cout << std::endl
                        << "Enter the student ID + Name + Item number you want(All at once like this : 40322943 Ali 1) : " << std::endl;
                getline(std::cin, line);
                std::istringstream iss(line);
                std::string word;

                int i = 0;
                while (iss >> word) {
                    if (i == 0) {
                        if (validateID(word)) {
                            currentID = word;
                        } else {
                            std::cout << "Invalid ID (it must contain 8 numbers)" << std::endl;
                            exit(1);
                        }
                    } else if (i == 1) {
                        currentName = word;
                    } else if (i == 2) {
                        if (validateItem(std::stoi(word))) {
                            currentItem = word;
                        } else {
                            std::cout << "Invalid Item (it must be between 1 to 9)" << std::endl;
                            exit(1);
                        }
                    }
                    i++;
                }
                currentItemINT = stoi(currentItem);
                if (currentItemINT == 1) {
                    order = new Order(currentID, currentName, *(menu->pizza));
                    orderlist->addOrder(order);
                    if (stdorder->stdisAvailable(currentID)) {
                        stdorder->addtoStd(menu->pizza, currentID);
                    } else {
                        auto* tmp = new IndividualOrders(currentID, currentName);
                        stdorder->addStd(tmp);
                        stdorder->addtoStd(menu->pizza, currentID);
                    }
                } else if (currentItemINT == 2) {
                    order = new Order(currentID, currentName, *(menu->burger));
                    orderlist->addOrder(order);
                    if (stdorder->stdisAvailable(currentID)) {
                        stdorder->addtoStd(menu->burger, currentID);
                    } else {
                        auto* tmp = new IndividualOrders(currentID, currentName);
                        stdorder->addStd(tmp);
                        stdorder->addtoStd(menu->burger, currentID);
                    }
                } else if (currentItemINT == 3) {
                    order = new Order(currentID, currentName, *(menu->kabab));
                    orderlist->addOrder(order);
                    if (stdorder->stdisAvailable(currentID)) {
                        stdorder->addtoStd(menu->kabab, currentID);
                    } else {
                        auto* tmp = new IndividualOrders(currentID, currentName);
                        stdorder->addStd(tmp);
                        stdorder->addtoStd(menu->kabab, currentID);
                    }
                } else if (currentItemINT == 4) {
                    order = new Order(currentID, currentName, *(menu->coffee));
                    orderlist->addOrder(order);
                    if (stdorder->stdisAvailable(currentID)) {
                        stdorder->addtoStd(menu->coffee, currentID);
                    } else {
                        auto* tmp = new IndividualOrders(currentID, currentName);
                        stdorder->addStd(tmp);
                        stdorder->addtoStd(menu->coffee, currentID);
                    }
                } else if (currentItemINT == 5) {
                    order = new Order(currentID, currentName, *(menu->cola));
                    orderlist->addOrder(order);
                    if (stdorder->stdisAvailable(currentID)) {
                        stdorder->addtoStd(menu->cola, currentID);
                    } else {
                        auto* tmp = new IndividualOrders(currentID, currentName);
                        stdorder->addStd(tmp);
                        stdorder->addtoStd(menu->cola, currentID);
                    }
                } else if (currentItemINT == 6) {
                    order = new Order(currentID, currentName, *(menu->water));
                    orderlist->addOrder(order);
                    if (stdorder->stdisAvailable(currentID)) {
                        stdorder->addtoStd(menu->water, currentID);
                    } else {
                        auto* tmp = new IndividualOrders(currentID, currentName);
                        stdorder->addStd(tmp);
                        stdorder->addtoStd(menu->water, currentID);
                    }
                } else if (currentItemINT == 7) {
                    order = new Order(currentID, currentName, *(menu->soup));
                    orderlist->addOrder(order);
                    if (stdorder->stdisAvailable(currentID)) {
                        stdorder->addtoStd(menu->soup, currentID);
                    } else {
                        auto* tmp = new IndividualOrders(currentID, currentName);
                        stdorder->addStd(tmp);
                        stdorder->addtoStd(menu->soup, currentID);
                    }
                } else if (currentItemINT == 8) {
                    order = new Order(currentID, currentName, *(menu->jelly));
                    orderlist->addOrder(order);
                    if (stdorder->stdisAvailable(currentID)) {
                        stdorder->addtoStd(menu->jelly, currentID);
                    } else {
                        auto* tmp = new IndividualOrders(currentID, currentName);
                        stdorder->addStd(tmp);
                        stdorder->addtoStd(menu->jelly, currentID);
                    }
                } else if (currentItemINT == 9) {
                    order = new Order(currentID, currentName, *(menu->fruitDish));
                    orderlist->addOrder(order);
                    if (stdorder->stdisAvailable(currentID)) {
                        stdorder->addtoStd(menu->fruitDish, currentID);
                    } else {
                        auto* tmp = new IndividualOrders(currentID, currentName);
                        stdorder->addStd(tmp);
                        stdorder->addtoStd(menu->fruitDish, currentID);
                    }
                }
            }
            case 3:;

        }

    }

};

void showCommands() {
    std::cout << termcolor::bright_yellow << "   1. Show the menu" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_yellow << "   2. New order" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_yellow << "   3. Order delivered" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_yellow << "   4. Cancel order" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_yellow << "   5. Change order" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_yellow << "   6. Review" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_red << "   0. EXIT" << termcolor::reset << std::endl;
}

bool validateID(std::string stdID) {
    if (stdID.length() != 8) {
        return false;
    }
    return true;
}
bool NameIsNew(std::string stdName) {

}
bool validateItem(int stdItem) {
    if (stdItem <= 0 || stdItem > 9) {
        return false;
    }
    return true;
}