#ifndef TILE1B
#define TILE1B

#include <string>
#include "World.h"

class Tile1B : public World {
public:
    Tile1B();

    //std::string gatherUserInput() override;
    World moveToNextTile(std::string tileSelection) override;
    void displayText(Creature& creature) override;
private:
};

#endif
