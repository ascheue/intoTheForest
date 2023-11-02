#ifndef CURRENTTILE_H
#define CURRENTTILE_H

#include "World.h"

class CurrentTile : public World {
public:
    //Constructor
    CurrentTile();

    int getCurrentTile() override;

    bool tileIsAdjacent(World_location tile) override;

    void moveToNextTile(World_location tileSelection);

    void equals(const World& otherWorld);

private:
};

#endif
