#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <vector>

typedef enum
{
    startingArea,
    Area1A,
    Area1B,
    Area1C,
} World_location;

class World {
private:

protected:
    std::string currentName;
    int currentID;
    int numAdjacents;
    int listOfAdjacents[100];
    bool isCurrentLevel;
    bool hasBeenVisited;

public:
    World();

    virtual int getCurrentTile();

    virtual bool tileIsAdjacent(World_location tile);

    void moveToNextTile(World_location tileSelection);

};

#endif 