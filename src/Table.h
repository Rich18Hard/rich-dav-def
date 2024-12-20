#ifndef TABLE_H
#define TABLE_H

#include "Customer.h"

class Table {
private:
    int tableNumber;
    bool isOccupied;
    Customer* seatedCustomer;  // Pointer to Customer (base class)
    bool orderTaken;
    bool orderProcessed;
    bool hasDirtyPlates;
    bool orderServed;

public:
    Table();
    Table(int tableNumber);

    // Seating/Unseating
    bool seatCustomer(Customer* customer);
    bool unseatCustomer();

    // Getters
    bool getOccupiedStatus() const;
    int getTableNumber() const;
    Customer* getSeatedCustomer() const;

    // Order Handling
    bool takeOrder();
    bool processOrder();
    bool serveOrder();
    bool hasOrderTaken() const;
    bool isOrderProcessed() const;
    bool isOrderServed() const;

    // Cleaning
    bool hasDirtyPlatesStatus() const;
    bool cleanTable();
};

#endif
