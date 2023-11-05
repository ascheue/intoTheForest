#ifndef STARTINGTILE_H
#define STARTINGTILE_H

#include "World.h"
//#include "CurrentTile.h"

class StartingTile : public World {
public:
    //Constructor
    StartingTile();

    void displayText() override;
    void moveToNextTile(World& currentTile, std::string tileSelection) override;

private:
};

#endif
