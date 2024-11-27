#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
private:
    int customerCount;
    int emotion;

public:
    Customer();
    Customer(int count, int emotion);

    void setCustomerCount(int count);
    void setEmotion(int emotion);
    int getCustomerCount() const;
    int getEmotion() const;
};

#endif // CUSTOMER_H
