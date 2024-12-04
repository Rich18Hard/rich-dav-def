#include "Table.h"

Table::Table() : tableNumber(0), isOccupied(false), seatedCustomer(nullptr), orderTaken(false), orderProcessed(false), hasDirtyPlates(false), orderServed(false) {}

Table::Table(int tableNumber)
    : tableNumber(tableNumber), isOccupied(false), seatedCustomer(nullptr), orderTaken(false), orderProcessed(false), hasDirtyPlates(false), orderServed(false) {}

bool Table::seatCustomer(Customer* customer) {
    if (!isOccupied) {
        seatedCustomer = customer;
        isOccupied = true;
        return true;
    }
    return false;
}

bool Table::unseatCustomer() {
    if (isOccupied && orderServed) {
        hasDirtyPlates = true;
        isOccupied = false;
        orderTaken = false;
        orderProcessed = false;
        orderServed = false;
        seatedCustomer = nullptr;  // Reset the pointer
        return true;
    }
    return false;
}

bool Table::getOccupiedStatus() const {
    return isOccupied;
}

int Table::getTableNumber() const {
    return tableNumber;
}

Customer* Table::getSeatedCustomer() const {
    return seatedCustomer;
}

bool Table::takeOrder() {
    if (isOccupied && !orderTaken) {
        orderTaken = true;
        return true;
    }
    return false;
}

bool Table::processOrder() {
    if (orderTaken && !orderProcessed) {
        orderProcessed = true;
        return true;
    }
    return false;
}

bool Table::serveOrder() {
    if (orderTaken && orderProcessed && !orderServed) {
        orderServed = true;
        return true;
    }
    return false;
}

bool Table::hasOrderTaken() const {
    return orderTaken;
}

bool Table::isOrderProcessed() const {
    return orderProcessed;
}

bool Table::isOrderServed() const {
    return orderServed;
}

bool Table::hasDirtyPlatesStatus() const {
    return hasDirtyPlates;
}

bool Table::cleanTable() {
    if (hasDirtyPlates) {
        hasDirtyPlates = false;
        return true;
    }
    return false;
}
