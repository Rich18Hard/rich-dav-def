#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
private:
    int number;
    int emotion;

public:
    Customer();
    Customer(int number, int emotion);
    int getNumber() const;
    void setNumber(int number);
    int getEmotion() const;
    void setEmotion(int emotion);
};

#endif
