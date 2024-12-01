#include "Customer.h"

Customer::Customer() : number(0), emotion(5) {}

Customer::Customer(int number, int emotion) : number(number), emotion(emotion) {}

int Customer::getNumber() const {
    return number;
}

void Customer::setNumber(int number) {
    this->number = number;
}

int Customer::getEmotion() const {
    return emotion;
}

void Customer::setEmotion(int emotion) {
    this->emotion = emotion;
}
