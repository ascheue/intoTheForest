#ifndef STARTINGTILE_H
#define STARTINGTILE_H

#include "World.h"

class StartingTile : public World {
public:
    StartingTile();

    void displayText() override;
    void moveToNextTile(World& currentTile, std::string tileSelection) override;
private:
};

#endif
