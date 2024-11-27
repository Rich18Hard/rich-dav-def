#include "Queue.h"

void Queue::enqueue(Customer* customer) {
    customers.push(customer);
}

Customer* Queue::dequeue() {
    if (!customers.empty()) {
        Customer* customer = customers.front();
        customers.pop();
        return customer;
    }
    return nullptr;
}

bool Queue::isEmpty() const {
    return customers.empty();
}
