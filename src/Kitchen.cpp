#include "Kitchen.h"

void Kitchen::addOrder(int orderNumber, Order* order) {
    orders[orderNumber] = order;
}

void Kitchen::removeOrder(int orderNumber) {
    orders.erase(orderNumber);
}

Order* Kitchen::getOrder(int orderNumber) {
    return orders[orderNumber];
}
