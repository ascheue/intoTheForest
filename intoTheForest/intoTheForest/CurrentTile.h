#ifndef CURRENTTILE_H
#define CURRENTTILE_H

#include "World.h"

class CurrentTile : public World {
public:
    CurrentTile();

    World moveToNextTile(std::string tileSelection) override;
private:
};

#endif
