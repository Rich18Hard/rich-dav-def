#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include "Customer.h"

class Queue {
private:
    std::queue<Customer*> customers;

public:
    void enqueue(Customer* customer);
    Customer* dequeue();
    bool isEmpty() const;
};

#endif // QUEUE_H
