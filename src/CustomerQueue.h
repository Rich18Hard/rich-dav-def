#ifndef CUSTOMERQUEUE_H
#define CUSTOMERQUEUE_H

#include "Customer.h"

class CustomerQueue {
public:
    void enqueueCustomer(Customer* customer);
    Customer* dequeueCustomer();
    bool isQueueEmpty() const;
};

#endif // CUSTOMERQUEUE_H
