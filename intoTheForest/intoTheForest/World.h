#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <vector>

typedef enum
{
    startingTile,
    Tile1A,
    Tile1B,
    Tile1C,
    OOB,
} World_location;

class World {
private:

public:
    World_location locationEnum;
    std::string tileName;
    int tileID;
    int numAdjacents;
    World_location listOfAdjacents[100];
    bool isCurrentLevel;
    bool hasBeenVisited;

    World();

    virtual int getCurrentTile();

    virtual bool tileIsAdjacent(World_location tile);

    virtual void equals(const World& otherWorld);

    void moveToNextTile(World_location tileSelection);

};

#endif