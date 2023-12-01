#ifndef TILE2C
#define TILE2C

#include <string>
#include "World.h"

class Tile2C : public World {
public:
    Tile2C();

    //std::string gatherUserInput() override;
    //void clearPathForward(int i);
    void displayText(Creature& creature) override;
    World moveToNextTile(std::string tileSelection) override;
protected:
    std::string creatureDeadMessage;
};

#endif
