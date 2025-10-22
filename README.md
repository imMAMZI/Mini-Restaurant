# Mini-Restaurant

std::cout << termcolor::bright_blue << termcolor::blue << "All orders information : " << termcolor::reset
<< std::endl << std::endl;
Order* tmp = orderlist->tail;
while (tmp != nullptr) {
tmp->printOrder();
std::cout << termcolor::bright_red << "--------------------------" << termcolor::reset << std::endl;
std::cout << std::endl;
tmp = tmp->prev;
}
break;