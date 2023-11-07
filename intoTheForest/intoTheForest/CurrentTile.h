#ifndef CURRENTTILE_H
#define CURRENTTILE_H

#include "World.h"

class CurrentTile : public World {
public:
    CurrentTile();

    void displayText() override;
    void moveToNextTile(World& currentTile, std::string tileSelection) override;
private:
};

#endif
