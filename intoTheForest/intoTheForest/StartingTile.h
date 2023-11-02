#ifndef STARTINGTILE_H
#define STARTINGTILE_H

#include "World.h"

class StartingTile : public World {
public:
    //Constructor
    StartingTile();

    int getCurrentTile() override;

    bool tileIsAdjacent(World_location tile) override;

    void moveToNextTile(World_location tileSelection);

    void equals(const World& otherWorld);

private:
};

#endif
