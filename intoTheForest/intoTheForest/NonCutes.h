#ifndef NONCUTES_H
#define NONCUTES_H

#include "Creature.h"

class NonCutes : public Creature {
private:
protected:
public:
    NonCutes();
    void interact(Player &player) override;
};

#endif