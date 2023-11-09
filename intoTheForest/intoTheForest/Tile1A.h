#ifndef TILE1A
#define TILE1A

#include "World.h"

class Tile1A : public World {
public:
    Tile1A();

    World moveToNextTile(std::string tileSelection) override;
private:
};

#endif
