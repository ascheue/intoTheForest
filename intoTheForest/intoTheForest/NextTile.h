#ifndef NEXTTILE_H
#define NEXTTILE_H

#include "World.h"
//#include "CurrentTile.h"

class NextTile : public World {
public:
    //Constructor
    NextTile();

    void displayText() override;
    void moveToNextTile(World& currentTile, std::string tileSelection) override;

private:
};

#endif
