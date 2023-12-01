// MageGatheringTile.h
#ifndef MAGE_GATHERING_TILE_H
#define MAGE_GATHERING_TILE_H

#include "World.h"
#include <iostream>

class MageGatheringTile : public World {
public:
    MageGatheringTile();

    World moveToNextTile(std::string tileSelection) override;
};

#endif
