#ifndef DISHWASHER_H
#define DISHWASHER_H

class Dishwasher {
private:
    bool isOn;
    int money;

public:
    Dishwasher();
    void toggle();
    void generateMoney();
    int getMoney() const;
};

#endif // DISHWASHER_H
