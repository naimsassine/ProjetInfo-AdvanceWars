#include "player.h"
int Player::getMoney() const
{
    return money;
}

void Player::setMoney(int value)
{
    money = value;
}

int Player::getTeam() const
{
    return Team;
}

Player::Player(int Initmoney, int InitTeam)
{
    Team=InitTeam;
    money=Initmoney;
}


