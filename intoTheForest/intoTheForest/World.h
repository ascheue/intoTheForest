#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <vector>
#include <map>

class World {
private:

public:
    std::string tileName;
    int tileID;
    int numAdjacents;
    int numNavigations;
    std::vector<std::string> listOfNavigations;
    //std::string listOfNavigations[100];
    std::vector<World> listOfAdjacents;
    bool isCurrentLevel;
    bool hasBeenVisited;
    std::map<std::string, World> actionsToAdvanceTile;

    World();

    virtual void displayText();
    std::string gatherUserInput();
    World getCurrentWorld();
    virtual int getCurrentTileID();
    virtual std::string getCurrentTileName();
    virtual bool tileIsAdjacent(World tile);
    void equals(const World& otherWorld);
    virtual void moveToNextTile(World& currentTile, std::string tileSelection);

};

#endif