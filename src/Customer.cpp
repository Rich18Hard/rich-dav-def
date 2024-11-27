#include "Customer.h"

Customer::Customer() : customerCount(0), emotion(5) {}

Customer::Customer(int count, int emotion) : customerCount(count), emotion(emotion) {}

void Customer::setCustomerCount(int count) {
    customerCount = count;
}

void Customer::setEmotion(int emotion) {
    this->emotion = emotion;
}

int Customer::getCustomerCount() const {
    return customerCount;
}

int Customer::getEmotion() const {
    return emotion;
}
