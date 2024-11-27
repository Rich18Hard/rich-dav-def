#ifndef TABLE_H
#define TABLE_H

#include "Order.h"

class Table {
private:
    int customerCount;
    bool servingStatus;
    Order* currentOrder;

public:
    Table();
    
    void setCustomerCount(int count);
    void setServingStatus(bool status);

    int getCustomerCount() const;
    bool getServingStatus() const;

    void setOrder(Order* order);
    Order* getCurrentOrder() const;
};

#endif // TABLE_H
