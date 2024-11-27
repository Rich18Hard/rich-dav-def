#include "CustomerQueue.h"
#include "Queue.h"

Queue queueManager;

void CustomerQueue::enqueueCustomer(Customer* customer) {
    queueManager.enqueue(customer);
}

Customer* CustomerQueue::dequeueCustomer() {
    return queueManager.dequeue();
}

bool CustomerQueue::isQueueEmpty() const {
    return queueManager.isEmpty();
}
