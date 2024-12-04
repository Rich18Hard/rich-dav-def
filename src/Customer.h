#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
protected:
    int number;
    int emotion;

public:
    Customer();
    Customer(int number, int emotion);
    virtual ~Customer() = default; // Virtual destructor for polymorphism

    int getNumber() const;
    void setNumber(int number);
    int getEmotion() const;
    void setEmotion(int emotion);

    virtual std::string getPersonality() const = 0;  // Pure virtual function
};

// Subclasses
class ImpatientCustomer : public Customer {
public:
    ImpatientCustomer(int number, int emotion);
    std::string getPersonality() const override;
};

class PatientCustomer : public Customer {
public:
    PatientCustomer(int number, int emotion);
    std::string getPersonality() const override;
};

class LoyalCustomer : public Customer {
public:
    LoyalCustomer(int number, int emotion);
    std::string getPersonality() const override;
};

#endif
