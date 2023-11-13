#ifndef TILE1A
#define TILE1A

#include <string>
#include "World.h"

class Tile1A : public World {
public:
    Tile1A();

    std::string gatherUserInput() override;
    World moveToNextTile(std::string tileSelection) override;
    void setNextAction(std::string action) override;
    std::string getNextAction() override;
private:
};

#endif
