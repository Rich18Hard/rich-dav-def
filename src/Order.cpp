#include "Order.h"

Order::Order(int orderNumber) : orderNumber(orderNumber), isServed(false) {}

void Order::serveOrder() {
    isServed = true;
}

bool Order::getIsServed() const {
    return isServed;
}
