#include "Dishwasher.h"
#include <iostream>

Dishwasher::Dishwasher() : isOn(false), money(0) {}

void Dishwasher::toggle() {
    isOn = !isOn;
    std::cout << "Dishwasher is now " << (isOn ? "On" : "Off") << ".\n";
}

void Dishwasher::generateMoney() {
    if (isOn) {
        money += 10;  // Simulate generating money
        std::cout << "Generated money. Current balance: $" << money << ".\n";
    }
}

int Dishwasher::getMoney() const {
    return money;
}
