#include "World.h"
#include "DataModule.h"
#include "Logger.h"
#include "StartingTile.h"
#include <iostream>

//Constructor
World::World() {}

int World::getCurrentTile() {
    //each tile class should have its own method
    return -1;
}

bool World::tileIsAdjacent(World_location tile) {
    /*for(int i=0; i<numAdjacents; i++){
        if(listOfAdjacents[i] == tile){
            return true;
        }
    }*/
    return false;
}

void World::moveToNextTile(World_location tileSelection) {
    //need to implement logic
}

void World::equals(const World& otherWorld) {
    /*currentName = otherWorld.currentName;
    currentID = otherWorld.currentID;
    numAdjacents = otherWorld.numAdjacents;
    for (int i = 0; i < numAdjacents; i++) {
        listOfAdjacents[i] = otherWorld.listOfAdjacents[i];
    }
    isCurrentLevel = otherWorld.isCurrentLevel;
    hasBeenVisited = otherWorld.hasBeenVisited;*/
}