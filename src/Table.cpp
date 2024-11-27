#include "Table.h"

Table::Table() : customerCount(0), servingStatus(false), currentOrder(nullptr) {}

void Table::setCustomerCount(int count) {
    customerCount = count;
}

void Table::setServingStatus(bool status) {
    servingStatus = status;
}

int Table::getCustomerCount() const {
    return customerCount;
}

bool Table::getServingStatus() const {
    return servingStatus;
}

void Table::setOrder(Order* order) {
    currentOrder = order;
}

Order* Table::getCurrentOrder() const {
    return currentOrder;
}
