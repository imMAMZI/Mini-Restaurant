#include <algorithm>
#include <iostream>

#include "libraries/menu.h"
#include "libraries/order.h"
#include <sstream>
#include "libraries/LLorders.h"
#include "libraries/studentorders.h"
#include "libraries/individualOrders.h"
#include "libraries/item.h"
#include "libraries/termcolor.hpp"

void showCommands();
bool validateID(std::string& stdID);
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

    while (input != 0) {
        showCommands();
        std::cin >> input;
        switch (input) {
            case 1:
                menu->showMenu();
                break;
            case 2: {
                menu->showMenu();
                status = false;
                while (!status) {
                    std::cout << std::endl
                        << "Enter the student ID + Name + Item number you want(All at once like this : 40322943 Ali 1) : " << std::endl;
                    std::cin >> currentID >> currentName >> currentItemINT;
                    if (!validateID(currentID)) {
                        std::cout << termcolor::red << "Invalid student ID" << std::endl;
                    } else if (!validateItem(currentItemINT)) {
                        std::cout << termcolor::red << "Invalid Item number" << std::endl;
                    }
                    else {
                        status = true;
                    }
                }
                if (currentItemINT == 1) {
                    auto* order = new Order(currentID, currentName, *(menu->pizza));
                    orderlist->addOrder(order);
                    if (stdorder->stdisAvailable(currentID)) {
                        stdorder->addtoStd(menu->pizza, currentID);
                        break;
                    } else {
                        auto* tmp = new IndividualOrders(currentID, currentName);
                        stdorder->addStd(tmp);
                        stdorder->addtoStd(menu->pizza, currentID);
                        break;
                    }
                } else if (currentItemINT == 2) {
                    auto* order = new Order(currentID, currentName, *(menu->burger));
                    orderlist->addOrder(order);
                    if (stdorder->stdisAvailable(currentID)) {
                        stdorder->addtoStd(menu->burger, currentID);
                        break;
                    } else {
                        auto* tmp = new IndividualOrders(currentName, currentID);
                        stdorder->addStd(tmp);
                        stdorder->addtoStd(menu->burger, currentID);
                        break;
                    }
                } else if (currentItemINT == 3) {
                    auto* order = new Order(currentID, currentName, *(menu->kabab));
                    orderlist->addOrder(order);
                    if (stdorder->stdisAvailable(currentID)) {
                        stdorder->addtoStd(menu->kabab, currentID);
                        break;
                    } else {
                        auto* tmp = new IndividualOrders(currentName, currentID);
                        stdorder->addStd(tmp);
                        stdorder->addtoStd(menu->kabab, currentID);
                        break;
                    }
                } else if (currentItemINT == 4) {
                    auto* order = new Order(currentID, currentName, *(menu->kabab));
                    orderlist->addOrder(order);
                    if (stdorder->stdisAvailable(currentID)) {
                        stdorder->addtoStd(menu->coffee, currentID);
                        break;
                    } else {
                        auto* tmp = new IndividualOrders(currentName, currentID);
                        stdorder->addStd(tmp);
                        stdorder->addtoStd(menu->coffee, currentID);
                        break;
                    }
                } else if (currentItemINT == 5) {
                    auto* order = new Order(currentID, currentName, *(menu->kabab));
                    orderlist->addOrder(order);
                    if (stdorder->stdisAvailable(currentID)) {
                        stdorder->addtoStd(menu->cola, currentID);
                        break;
                    } else {
                        auto* tmp = new IndividualOrders(currentName, currentID);
                        stdorder->addStd(tmp);
                        stdorder->addtoStd(menu->cola, currentID);
                        break;
                    }
                } else if (currentItemINT == 6) {
                    auto* order = new Order(currentID, currentName, *(menu->kabab));
                    orderlist->addOrder(order);
                    if (stdorder->stdisAvailable(currentID)) {
                        stdorder->addtoStd(menu->water, currentID);
                        break;
                    } else {
                        auto* tmp = new IndividualOrders(currentName, currentID);
                        stdorder->addStd(tmp);
                        stdorder->addtoStd(menu->water, currentID);
                        break;
                    }
                } else if (currentItemINT == 7) {
                    auto* order = new Order(currentID, currentName, *(menu->kabab));
                    orderlist->addOrder(order);
                    if (stdorder->stdisAvailable(currentID)) {
                        stdorder->addtoStd(menu->soup, currentID);
                        break;
                    } else {
                        auto* tmp = new IndividualOrders(currentName, currentID);
                        stdorder->addStd(tmp);
                        stdorder->addtoStd(menu->soup, currentID);
                        break;
                    }
                } else if (currentItemINT == 8) {
                    auto* order = new Order(currentID, currentName, *(menu->kabab));
                    orderlist->addOrder(order);
                    if (stdorder->stdisAvailable(currentID)) {
                        stdorder->addtoStd(menu->jelly, currentID);
                        break;
                    } else {
                        auto* tmp = new IndividualOrders(currentName, currentID);
                        stdorder->addStd(tmp);
                        stdorder->addtoStd(menu->jelly, currentID);
                        break;
                    }
                } else if (currentItemINT == 9) {
                    auto* order = new Order(currentID, currentName, *(menu->kabab));
                    orderlist->addOrder(order);
                    if (stdorder->stdisAvailable(currentID)) {
                        stdorder->addtoStd(menu->fruitDish, currentID);
                        break;
                    } else {
                        auto* tmp = new IndividualOrders(currentName, currentID);
                        stdorder->addStd(tmp);
                        stdorder->addtoStd(menu->fruitDish, currentID);
                        break;
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
                            std::cout << termcolor::red << "Order canceled or already received" << termcolor::reset << std::endl;
                            status = true;
                            break;
                        }
                        tmp->changeOrderStatus(1);
                        std::cout << termcolor::bright_green << "Order Delivered successfully" << termcolor::reset << std::endl;
                        status = true;
                        break;
                    } else {
                        tmp = tmp->next;
                    }
                }
                if (!status) {
                    std::cout << termcolor::red << "Order number not valid" << termcolor::reset << std::endl;
                }
                break;
            }
            case 4: {
                std::cout << "Enter the order's number : " << std::endl;
                std::cin >> orderNum;
                status = false;
                Order* tmp = orderlist->head;
                while (tmp != nullptr) {
                    if (tmp->thisOrderNumber == orderNum) {
                        if (tmp->getOrderStatus() == 1) {
                            std::cout << termcolor::red << "Order already received" << termcolor::reset << std::endl;
                            status = true;
                            break;
                        } else {
                            tmp->changeOrderStatus(2);
                            std::cout << termcolor::bright_green << "Order canceled successfully" << termcolor::reset << std::endl;
                            status = true;
                            break;
                        }
                    } else {
                        tmp = tmp->next;
                    }
                }
                if (!status) {
                    std::cout << termcolor::red << "Order number not valid" << termcolor::reset << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "Enter the order's number : " << std::endl;
                std::cin >> orderNum;
                status = false;
                Order* tmp = orderlist->head;
                while (tmp != nullptr) {
                    if (tmp->thisOrderNumber == orderNum) {
                        if (tmp->getOrderStatus() != 0) {
                            std::cout << termcolor::red << "Only 'pending' orders can be changed" << termcolor::reset << std::endl;
                            status = true;
                            break;
                        } else {
                            std::cout << "Commands : " << std::endl;
                            std::cout << "   1. Add to order" << "   2. Delete from order" << std::endl
                            << "   3. Change one item" << std::endl;
                            std::cin >> currentCommand;
                            while (currentCommand < 1 || currentCommand > 3) {
                                std::cout << termcolor::red << "Command not valid, try again : " << termcolor::reset << std::endl;
                                std::cin >> currentCommand;
                                break;
                            }
                            if (currentCommand == 1) {
                                menu->showMenu();
                                std::cout << std::endl << "Choose the item to add : " << std::endl;
                                std::cin >> currentItemINT;
                                while (!validateItem(currentItemINT)) {
                                    std::cout << termcolor::red << "Invalid item number (enter sth between 1 and 9)"
                                    << termcolor::reset << std::endl;
                                    std::cin >> currentItemINT;
                                }
                                if (currentItemINT == 1) {
                                    tmp->addToOrder(*(menu->pizza));
                                    status = true;
                                } else if (currentItemINT == 2) {
                                    tmp->addToOrder(*(menu->burger));
                                    status = true;
                                } else if (currentItemINT == 3) {
                                    tmp->addToOrder(*(menu->kabab));
                                    status = true;
                                } else if (currentItemINT == 4) {
                                    tmp->addToOrder(*(menu->coffee));
                                    status = true;
                                } else if (currentItemINT == 5) {
                                    tmp->addToOrder(*(menu->cola));
                                    status = true;
                                } else if (currentItemINT == 6) {
                                    tmp->addToOrder(*(menu->water));
                                    status = true;
                                } else if (currentItemINT == 7) {
                                    tmp->addToOrder(*(menu->soup));
                                    status = true;
                                } else if (currentItemINT == 8) {
                                    tmp->addToOrder(*(menu->jelly));
                                    status = true;
                                } else if (currentItemINT == 9) {
                                    tmp->addToOrder(*(menu->fruitDish));status = true;
                                    status = true;
                                }
                                break;
                            } else if (currentCommand == 2) {
                                tmp->printOrder();
                                std::cout << std::endl << termcolor::bright_blue << termcolor::bold << "Choose which to remove : "
                                << termcolor::reset << std::endl
                                << "   1. Pizza  2. Burger  3. Kabab  4. Coffee  5. cola  6. Water  7. Soup  8. Jelly  9. FruitDish"
                                << std::endl;
                                std::cin >> currentItemINT;
                                while (!validateItem(currentItemINT)) {
                                    std::cout << termcolor::red << "Invalid item number (enter sth between 1 and 9)" << termcolor::reset << std::endl;
                                    std::cin >> currentItemINT;
                                }
                                if (currentItemINT == 1) {
                                    tmp->deleteFromOrder("Pizza");
                                    status = true;
                                } else if (currentItemINT == 2) {
                                    tmp->deleteFromOrder("Burger");
                                    status = true;
                                } else if (currentItemINT == 3) {
                                    tmp->deleteFromOrder("Kabab");
                                    status = true;
                                } else if (currentItemINT == 4) {
                                    tmp->deleteFromOrder("Coffee");
                                    status = true;
                                } else if (currentItemINT == 5) {
                                    tmp->deleteFromOrder("Cola");
                                    status = true;
                                } else if (currentItemINT == 6) {
                                    tmp->deleteFromOrder("water");
                                    status = true;
                                } else if (currentItemINT == 7) {
                                    tmp->deleteFromOrder("Soup");
                                    status = true;
                                } else if (currentItemINT == 8) {
                                    tmp->deleteFromOrder("Jelly");
                                    status = true;
                                } else if (currentItemINT == 9) {
                                    tmp->deleteFromOrder("FruitDish");
                                    status = true;
                                }
                                break;
                            } else if (currentCommand == 3) {
                                tmp->printOrder();
                                std::cout << std::endl << termcolor::bright_blue << termcolor::bold << "Choose which to remove : "
                                << termcolor::reset << std::endl
                                << "   1. Pizza  2. Burger  3. Kabab  4. Coffee  5. cola  6. Water  7. Soup  8. Jelly  9. FruitDish"
                                << std::endl;
                                std::cin >> currentItemINT;
                                while (!validateItem(currentItemINT)) {
                                    std::cout << termcolor::red << "Invalid item number (enter sth between 1 and 9)" << termcolor::reset << std::endl;
                                    std::cin >> currentItemINT;
                                }
                                if (currentItemINT == 1) {
                                    tmp->deleteFromOrder("Pizza");
                                    status = true;
                                } else if (currentItemINT == 2) {
                                    tmp->deleteFromOrder("Burger");
                                    status = true;
                                } else if (currentItemINT == 3) {
                                    tmp->deleteFromOrder("Kabab");
                                    status = true;
                                } else if (currentItemINT == 4) {
                                    tmp->deleteFromOrder("Coffee");
                                    status = true;
                                } else if (currentItemINT == 5) {
                                    tmp->deleteFromOrder("Cola");
                                    status = true;
                                } else if (currentItemINT == 6) {
                                    tmp->deleteFromOrder("water");
                                    status = true;
                                } else if (currentItemINT == 7) {
                                    tmp->deleteFromOrder("Soup");
                                    status = true;
                                } else if (currentItemINT == 8) {
                                    tmp->deleteFromOrder("Jelly");
                                    status = true;
                                } else if (currentItemINT == 9) {
                                    tmp->deleteFromOrder("FruitDish");
                                    status = true;
                                }
                                std::cout << std::endl;
                                menu->showMenu();
                                std::cout << std::endl << "Choose the item to add : " << std::endl;
                                std::cin >> currentItemINT;
                                while (!validateItem(currentItemINT)) {
                                    std::cout << termcolor::red << "Invalid item number (enter sth between 1 and 9)" << termcolor::reset << std::endl;
                                    std::cin >> currentItemINT;
                                }
                                if (currentItemINT == 1) {
                                    tmp->addToOrder(*(menu->pizza));
                                    status = true;
                                } else if (currentItemINT == 2) {
                                    tmp->addToOrder(*(menu->burger));
                                    status = true;
                                } else if (currentItemINT == 3) {
                                    tmp->addToOrder(*(menu->kabab));
                                    status = true;
                                } else if (currentItemINT == 4) {
                                    tmp->addToOrder(*(menu->coffee));
                                    status = true;
                                } else if (currentItemINT == 5) {
                                    tmp->addToOrder(*(menu->cola));
                                    status = true;
                                } else if (currentItemINT == 6) {
                                    tmp->addToOrder(*(menu->water));
                                    status = true;
                                } else if (currentItemINT == 7) {
                                    tmp->addToOrder(*(menu->soup));
                                    status = true;
                                } else if (currentItemINT == 8) {
                                    tmp->addToOrder(*(menu->jelly));
                                    status = true;
                                } else if (currentItemINT == 9) {
                                    tmp->addToOrder(*(menu->fruitDish));
                                    status = true;
                                }
                                break;
                            }
                        }
                    } else {
                        tmp = tmp->next;
                    }
                }
                if (!status) {
                    std::cout << termcolor::red << "Order number not valid" << termcolor::reset << std::endl;
                }
                break;
            }
            case 6: {
                std::cout << termcolor::bright_blue << termcolor::blue << "All orders information : " << termcolor::reset
                << std::endl << std::endl;
                Order* tmp = orderlist->head;
                while (tmp != nullptr) {
                    tmp->printOrder();
                    std::cout << termcolor::bright_red << "--------------------------" << termcolor::reset << std::endl;
                    std::cout << std::endl;
                    tmp = tmp->next;
                }
                break;
            }
            case 0: {
                std::cout << termcolor::yellow << termcolor::bold << "Have a great day!" << termcolor::reset << std::endl;
                return 0;
            }
            default:
                std::cout << termcolor::red << "Wrong command. try again (should be sth between 0 and 6)" << termcolor::reset << std::endl;
                break;
        }
    }
    return 0;
}

void showCommands() {
    std::cout << std::endl;
    std::cout << termcolor::bright_yellow << "   1. Show the menu" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_yellow << "   2. New order" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_yellow << "   3. Order delivered" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_yellow << "   4. Cancel order" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_yellow << "   5. Change order" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_yellow << "   6. Review" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_red << "   0. EXIT" << termcolor::reset << std::endl;
    std::cout << std::endl;
}

bool validateID(std::string& stdID) {
    if (stdID.length() != 8) {
        return false;
    }
    if (stdID.empty() || !std::all_of(stdID.begin(), stdID.end(), ::isdigit)) {
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