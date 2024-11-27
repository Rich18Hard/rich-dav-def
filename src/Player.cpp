#include "Player.h"

Player::Player() : playerID(0), money(0) {}

void Player::setPlayerID(int id) {
    playerID = id;
}

void Player::setMoney(int money) {
    this->money = money;
}

int Player::getPlayerID() const {
    return playerID;
}

int Player::getMoney() const {
    return money;
}
