#ifndef PREVIOUSTILE_H
#define PREVIOUSTILE_H

#include "World.h"
//extern CurrentTile currentTile;

class PreviousTile : public World {
public:
    //Constructor
    PreviousTile();

    void displayText() override;
    void moveToNextTile(World& currentTile, std::string tileSelection) override;

private:
};

#endif
