#ifndef KITCHEN_H
#define KITCHEN_H

#include <unordered_map>
#include "Order.h"

class Kitchen {
private:
    std::unordered_map<int, Order*> orders;

public:
    void addOrder(int orderNumber, Order* order);
    void removeOrder(int orderNumber);
    Order* getOrder(int orderNumber);
};

#endif // KITCHEN_H
