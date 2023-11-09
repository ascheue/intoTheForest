#ifndef TILE1B
#define TILE1B

#include "World.h"

class Tile1B : public World {
public:
    Tile1B();

    World moveToNextTile(std::string tileSelection) override;
private:
};

#endif
