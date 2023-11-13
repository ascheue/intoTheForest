#ifndef STARTINGTILE_H
#define STARTINGTILE_H

#include <string>
#include "World.h"

class StartingTile : public World {
public:
    StartingTile();

    std::string gatherUserInput() override;
    World moveToNextTile(std::string tileSelection) override;
    void setNextAction(std::string action) override;
private:
};

#endif
