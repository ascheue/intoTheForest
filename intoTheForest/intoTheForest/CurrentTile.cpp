#include "World.h"
#include "CurrentTile.h"
#include <iostream>

//Constructor
CurrentTile::CurrentTile() {
    locationEnum = OOB;
    tileName = "nullTile";
    tileID = -1;
    numAdjacents = 0;
    listOfAdjacents[0] = OOB;
    listOfAdjacents[1] = OOB;
    listOfAdjacents[2] = OOB;
    listOfAdjacents[3] = OOB;
    listOfAdjacents[4] = OOB;
    listOfAdjacents[5] = OOB;
    listOfAdjacents[6] = OOB;
    listOfAdjacents[7] = OOB;
    listOfAdjacents[8] = OOB;
    listOfAdjacents[9] = OOB;
    isCurrentLevel = 0; //may not need 
    hasBeenVisited = 0;
}

int CurrentTile::getCurrentTile() {
    return tileID;
}

bool CurrentTile::tileIsAdjacent(World_location tile) {
    for(int i=0; i<numAdjacents; i++){
        if(listOfAdjacents[i] == tile){
            return true;
        }
    }
    return false;
}

void CurrentTile::equals(const World& otherWorld) {
    tileName = otherWorld.tileName;
    tileID = otherWorld.tileID;
    numAdjacents = otherWorld.numAdjacents;
    for (int i = 0; i < numAdjacents; i++) {
        listOfAdjacents[i] = otherWorld.listOfAdjacents[i];
    }
    isCurrentLevel = otherWorld.isCurrentLevel;
    hasBeenVisited = otherWorld.hasBeenVisited;
}

//bool CurrentTile::moveToNextTile(World_location tileSelection) {}


