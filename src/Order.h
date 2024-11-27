#ifndef ORDER_H
#define ORDER_H

class Order {
private:
    int orderNumber;
    bool isServed;

public:
    Order(int orderNumber);
    void serveOrder();
    bool getIsServed() const;
};

#endif // ORDER_H
