#ifndef CURRENTTILE_H
#define CURRENTTILE_H

#include "World.h"
//extern CurrentTile currentTile;

class CurrentTile : public World {
public:
    //Constructor
    CurrentTile();

    void displayText() override;
    void moveToNextTile(World& currentTile, std::string tileSelection) override;

private:
};

#endif
