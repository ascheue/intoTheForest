#ifndef TILE1C
#define TILE1C

#include "World.h"

class Tile1C : public World {
public:
    Tile1C();

    void clearPathForward(int i);
    World moveToNextTile(std::string tileSelection) override;
private:
};

#endif
