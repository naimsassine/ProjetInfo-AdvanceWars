#ifndef PLAYER_H
#define PLAYER_H
class Player{
public:
    Player(int Initmoney,int InitTeam);
    int getMoney() const;
    void setMoney(int value);

    int getTeam() const;

private:
    int money;
    int Team;
};
#endif // PLAYER_H
