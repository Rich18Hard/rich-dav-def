#ifndef CUSTOMERQUEUE_H
#define CUSTOMERQUEUE_H

#include <queue>
#include "Customer.h"

class CustomerQueue {
private:
    std::queue<Customer> customers;
    static const int maxCapacity = 12;

public:
    bool enqueueCustomer(const Customer& customer);
    bool dequeueCustomer();
    Customer frontCustomer() const;
    int getSize() const;
    bool isFull() const;
};

#endif
