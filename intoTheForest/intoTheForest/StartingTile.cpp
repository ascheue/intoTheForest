#include "World.h"
#include "StartingTile.h"
#include <iostream>

//Constructor
StartingTile::StartingTile() {
    locationEnum = startingTile;
    tileName = "StartingTile";
    tileID = 0;
    numAdjacents = 3;
    listOfAdjacents[0] = Tile1A;
    listOfAdjacents[1] = Tile1B;
    listOfAdjacents[2] = Tile1C;
    listOfAdjacents[3] = OOB;
    listOfAdjacents[4] = OOB;
    listOfAdjacents[5] = OOB;
    listOfAdjacents[6] = OOB;
    listOfAdjacents[7] = OOB;
    listOfAdjacents[8] = OOB;
    listOfAdjacents[9] = OOB;
    isCurrentLevel = 1; //may not need
    hasBeenVisited = 1;
}

int StartingTile::getCurrentTile() {
    return tileID;
}

bool StartingTile::tileIsAdjacent(World_location tile) {
    for(int i=0; i<numAdjacents; i++){
        if(listOfAdjacents[i] == tile){
            return true;
        }
    }
    return false;
}

void StartingTile::equals(const World& otherWorld) {
    tileName = otherWorld.tileName;
    tileID = otherWorld.tileID;
    numAdjacents = otherWorld.numAdjacents;
    for (int i = 0; i < numAdjacents; i++) {
        listOfAdjacents[i] = otherWorld.listOfAdjacents[i];
    }
    isCurrentLevel = otherWorld.isCurrentLevel;
    hasBeenVisited = otherWorld.hasBeenVisited;
}

//bool StartingTile::moveToNextTile(World_location tileSelection) {}




















