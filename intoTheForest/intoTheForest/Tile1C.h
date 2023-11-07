#ifndef TILE1C
#define TILE1C

#include "World.h"

class Tile1C : public World {
public:
    Tile1C();

    void displayText() override;
    void moveToNextTile(World& currentTile, std::string tileSelection) override;
private:
};

#endif
