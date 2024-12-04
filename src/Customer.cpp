#include "Customer.h"
#include <cstdlib>
#include <ctime>

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

// Derived class implementations
ImpatientCustomer::ImpatientCustomer(int number, int emotion) : Customer(number, emotion) {}

std::string ImpatientCustomer::getPersonality() const {
    return "Impatient";
}

PatientCustomer::PatientCustomer(int number, int emotion) : Customer(number, emotion) {}

std::string PatientCustomer::getPersonality() const {
    return "Patient";
}

LoyalCustomer::LoyalCustomer(int number, int emotion) : Customer(number, emotion) {}

std::string LoyalCustomer::getPersonality() const {
    return "Loyal";
}
