#ifndef CURRENTTILE_H
#define CURRENTTILE_H

#include <string>
#include "World.h"

class CurrentTile : public World {
public:
    CurrentTile();

    std::string gatherUserInput() override;
    World moveToNextTile(std::string tileSelection) override;
    void setNextAction(std::string action) override;
private:
};

#endif
