#ifndef STARTINGTILE_H
#define STARTINGTILE_H

#include "World.h"

class StartingTile : public World {
public:
    StartingTile();

    World moveToNextTile(std::string tileSelection) override;
private:
};

#endif
