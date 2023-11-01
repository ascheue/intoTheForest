#include "StartingTile.h"
#include <iostream>

//Constructor
StartingTile::StartingTile() {
    currentName = "StartingTile";
    currentID = 0;
    numAdjacents = 3;
    listOfAdjacents[0] = Area1A;
    listOfAdjacents[1] = Area1B;
    listOfAdjacents[2] = Area1C;
    isCurrentLevel = 1;
    hasBeenVisited = 1;
}

int StartingTile::getCurrentTile() {
    return currentID;
}

bool StartingTile::tileIsAdjacent(World_location tile) {
    for(int i=0; i<numAdjacents; i++){
        if(listOfAdjacents[i] == tile){
            return true;
        }
    }
    return false;
}

//bool StartingTile::moveToNextTile(World_location tileSelection) {}




















