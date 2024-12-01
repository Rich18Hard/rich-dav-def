#include "CustomerQueue.h"

bool CustomerQueue::enqueueCustomer(const Customer& customer) {
    if (customers.size() < maxCapacity) {
        customers.push(customer);
        return true;
    }
    return false; // Queue is full
}

bool CustomerQueue::dequeueCustomer() {
    if (!customers.empty()) {
        customers.pop();
        return true;
    }
    return false; // Queue is empty
}

Customer CustomerQueue::frontCustomer() const {
    return customers.front();
}

int CustomerQueue::getSize() const {
    return customers.size();
}

bool CustomerQueue::isFull() const {
    return customers.size() >= maxCapacity;
}
