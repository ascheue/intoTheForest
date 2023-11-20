#ifndef CREATURE_H
#define CREATURE_H

#include "Player.h"
#include "Logger.h"

class Creature{
private:
protected:
    Creature();
    int health;
    int attackStat;
    int defenseStat;
public:
    virtual int getHealth();
    virtual void setHealth(int hp);
    virtual int getAttackStat();
    virtual void setAttackStat(int attack);
    virtual int getDefenseStat();
    virtual void setDefenseStat(int defense);
    virtual void interact(Player &player);
    virtual int getRandom(int max);
};

#endif

