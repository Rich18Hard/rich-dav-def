#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int playerID;
    int money;

public:
    Player();
    void setPlayerID(int id);
    void setMoney(int money);
    int getPlayerID() const;
    int getMoney() const;
};

#endif // PLAYER_H
