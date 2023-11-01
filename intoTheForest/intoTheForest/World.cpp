#include "World.h"
#include "DataModule.h"
#include "Logger.h"
#include <iostream>

//Constructor
World::World() {}

int World::getCurrentTile() {
    //each tile class should have its own method
    return 0;
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
    
}