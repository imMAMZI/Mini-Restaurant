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
    int orderNum, currentCommand;
    bool status;
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
            case 3: {
                std::cout << "Enter the Order's number : " << std::endl;
                std::cin >> orderNum;
                status = false;
                Order* tmp = orderlist->head;
                while (tmp != nullptr) {
                    if (tmp->thisOrderNumber == orderNum) {
                        if (tmp->getOrderStatus() != 0) {
                            std::cout << "Order canceled or already received" << std::endl;
                            status = true;
                            break;
                        }
                        tmp->changeOrderStatus(1);
                        status = true;
                        break;
                    } else {
                        tmp = tmp->next;
                    }
                }
                if (!status) {
                    std::cout << "Order number not valid" << std::endl;
                    break;
                }
            }
            case 4: {
                std::cout << "Enter the order's number : " << std::endl;
                std::cin >> orderNum;
                status = false;
                Order* tmp = orderlist->head;
                while (tmp != nullptr) {
                    if (tmp->thisOrderNumber == orderNum) {
                        if (tmp->getOrderStatus() == 1) {
                            std::cout << "Order already received" << std::endl;
                            status = true;
                            break;
                        } else {
                            tmp->changeOrderStatus(0);
                            status = true;
                            break;
                        }
                    } else {
                        tmp = tmp->next;
                    }
                }
                if (!status) {
                    std::cout << "Order number not valid" << std::endl;
                    break;
                }
            }
            case 5: {
                std::cout << "Enter the order's number : " << std::endl;
                std::cin >> orderNum;
                status = false;
                Order* tmp = orderlist->head;
                while (tmp != nullptr) {
                    if (tmp->thisOrderNumber == orderNum) {
                        if (tmp->getOrderStatus() != 0) {
                            std::cout << "Only 'pending' orders can be changed" << std::endl;
                            status = true;
                            break;
                        } else {
                            std::cout << "Commands : " << std::endl;
                            std::cout << "   1. Add to order" << "   2. Delete from order" << std::endl
                            << "   3. Change one item" << std::endl;
                            std::cin >> currentCommand;
                            if (currentCommand < 1 || currentCommand > 3) {
                                std::cout << "Command not valid" << std::endl;
                                status = true;
                                break;
                            }
                            if (currentCommand == 1) {
                                menu->showMenu();
                                std::cout << std::endl << "Choose the item to add : " << std::endl;
                                std::cin >> currentItemINT;
                                while (!validateItem(currentItemINT)) {
                                    std::cout << "Invalid item number (enter sth between 1 and 9)" << std::endl;
                                    std::cin >> currentItemINT;
                                }
                                if (currentItemINT == 1) {
                                    tmp->addToOrder(*(menu->pizza));
                                } else if (currentItemINT == 2) {
                                    tmp->addToOrder(*(menu->burger));
                                } else if (currentItemINT == 3) {
                                    tmp->addToOrder(*(menu->kabab));
                                } else if (currentItemINT == 4) {
                                    tmp->addToOrder(*(menu->coffee));
                                } else if (currentItemINT == 5) {
                                    tmp->addToOrder(*(menu->cola));
                                } else if (currentItemINT == 6) {
                                    tmp->addToOrder(*(menu->water));
                                } else if (currentItemINT == 7) {
                                    tmp->addToOrder(*(menu->soup));
                                } else if (currentItemINT == 8) {
                                    tmp->addToOrder(*(menu->jelly));
                                } else if (currentItemINT == 9) {
                                    tmp->addToOrder(*(menu->fruitDish));
                                }
                                break;
                            } else if (currentCommand == 2) {
                                tmp->printOrder();
                                std::cout << "Choose which to remove : " << std::endl
                                << "   1. Pizza  2. Burger  3. Kabab  4. Coffee  5. cola  6. Water  7. Soup  8. Jelly  9. FruitDish"
                                << std::endl;
                                std::cin >> currentItemINT;
                                while (!validateItem(currentItemINT)) {
                                    std::cout << "Invalid item number (enter sth between 1 and 9)" << std::endl;
                                    std::cin >> currentItemINT;
                                }
                                if (currentItemINT == 1) {
                                    tmp->deleteFromOrder("Pizza");
                                } else if (currentItemINT == 2) {
                                    tmp->deleteFromOrder("Burger");
                                } else if (currentItemINT == 3) {
                                    tmp->deleteFromOrder("Kabab");
                                } else if (currentItemINT == 4) {
                                    tmp->deleteFromOrder("Coffee");
                                } else if (currentItemINT == 5) {
                                    tmp->deleteFromOrder("Cola");
                                } else if (currentItemINT == 6) {
                                    tmp->deleteFromOrder("water");
                                } else if (currentItemINT == 7) {
                                    tmp->deleteFromOrder("Soup");
                                } else if (currentItemINT == 8) {
                                    tmp->deleteFromOrder("Jelly");
                                } else if (currentItemINT == 9) {
                                    tmp->deleteFromOrder("FruitDish");
                                }
                                std::cout << std::endl;
                                menu->showMenu();
                                std::cout << std::endl << "Choose the item to add : " << std::endl;
                                std::cin >> currentItemINT;
                                while (!validateItem(currentItemINT)) {
                                    std::cout << "Invalid item number (enter sth between 1 and 9)" << std::endl;
                                    std::cin >> currentItemINT;
                                }
                                if (currentItemINT == 1) {
                                    tmp->addToOrder(*(menu->pizza));
                                } else if (currentItemINT == 2) {
                                    tmp->addToOrder(*(menu->burger));
                                } else if (currentItemINT == 3) {
                                    tmp->addToOrder(*(menu->kabab));
                                } else if (currentItemINT == 4) {
                                    tmp->addToOrder(*(menu->coffee));
                                } else if (currentItemINT == 5) {
                                    tmp->addToOrder(*(menu->cola));
                                } else if (currentItemINT == 6) {
                                    tmp->addToOrder(*(menu->water));
                                } else if (currentItemINT == 7) {
                                    tmp->addToOrder(*(menu->soup));
                                } else if (currentItemINT == 8) {
                                    tmp->addToOrder(*(menu->jelly));
                                } else if (currentItemINT == 9) {
                                    tmp->addToOrder(*(menu->fruitDish));
                                }
                                break;
                            } else if (currentCommand == 3) {
                                tmp->printOrder();
                                std::cout << "Choose which to remove : " << std::endl
                                << "   1. Pizza  2. Burger  3. Kabab  4. Coffee  5. cola  6. Water  7. Soup  8. Jelly  9. FruitDish"
                                << std::endl;
                                std::cin >> currentItemINT;
                                while (!validateItem(currentItemINT)) {
                                    std::cout << "Invalid item number (enter sth between 1 and 9)" << std::endl;
                                    std::cin >> currentItemINT;
                                }
                                if (currentItemINT == 1) {
                                    tmp->deleteFromOrder("Pizza");
                                } else if (currentItemINT == 2) {
                                    tmp->deleteFromOrder("Burger");
                                } else if (currentItemINT == 3) {
                                    tmp->deleteFromOrder("Kabab");
                                } else if (currentItemINT == 4) {
                                    tmp->deleteFromOrder("Coffee");
                                } else if (currentItemINT == 5) {
                                    tmp->deleteFromOrder("Cola");
                                } else if (currentItemINT == 6) {
                                    tmp->deleteFromOrder("water");
                                } else if (currentItemINT == 7) {
                                    tmp->deleteFromOrder("Soup");
                                } else if (currentItemINT == 8) {
                                    tmp->deleteFromOrder("Jelly");
                                } else if (currentItemINT == 9) {
                                    tmp->deleteFromOrder("FruitDish");
                                }
                                break;
                            }
                        }
                    } else {
                        tmp = tmp->next;
                    }
                }
                if (!status) {
                    std::cout << "Order number not valid" << std::endl;
                    break;
                }
            }
            case 6: {
                std::cout << "All orders information : " << std::endl << std::endl;
                Order* tmp = orderlist->head;
                while (tmp != nullptr) {
                    tmp->printOrder();
                    std::cout << std::endl;
                    tmp = tmp->next;
                }
                break;
            }
            case 0: {
                std::cout << "Have a great day!" << std::endl;
                return 0;
            }
            default:
                std::cout << "Wrong command. try again (should be sth between 0 and 6)" << std::endl;
                break;
        }
    }
    return 0;
}

void showCommands() {
    std::cout << termcolor::bright_yellow << "   1. Show the menu" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_yellow << "   2. New order" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_yellow << "   3. Order delivered" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_yellow << "   4. Cancel order" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_yellow << "   5. Change order" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_yellow << "   6. Review" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_red << "   0. EXIT" << termcolor::reset << std::endl;
}

bool validateID(const std::string& stdID) {
    if (stdID.length() != 8) {
        return false;
    }
    return true;
}
bool validateItem(const int stdItem) {
    if (stdItem <= 0 || stdItem > 9) {
        return false;
    }
    return true;
}