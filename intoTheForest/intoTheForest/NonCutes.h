#ifndef NONCUTES_H
#define NONCUTES_H

#include "Creature.h"

class NonCutes : public Creature {
private:
protected:
    int skinValue;
    bool isSkinned;
public:
    NonCutes();
    void interact(Player &player) override;
    void engageInCombat(Player &player) override;
    void examineBody(Player& player);
};

#endif