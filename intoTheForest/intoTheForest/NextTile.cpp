#include "World.h"
#include "NextTile.h"
#include "CurrentTile.h"
#include "StartingTile.h"
#include "PreviousTile.h"
#include <iostream>

World tiles[10];
//StartingTile* startingTilePtr = new StartingTile();

//Constructor
NextTile::NextTile() {
    //locationEnum = OOB;
    tileName = "nextTile";
    tileID = 1;
    numAdjacents = 0;
    numNavigations = 0;
    //listOfAdjacents = std::vector<World>();
    //listOfNavigations = std::vector<std::string>();

    //listOfAdjacents.push_back(otherTile);
    //listOfAdjacents[0] = otherTile;

    //listOfNavigations.push_back("go straight");
    //listOfNavigations[0] = "go straight";

    actionsToAdvanceTile["go back"] = PreviousTile();

    isCurrentLevel = 0; //may not need
    hasBeenVisited = 0;
}

void NextTile::displayText() {
    if(!hasBeenVisited){
        //Message for the first time you have entered zone/tile
    }
    else if(hasBeenVisited){
        //Message for already having been to this zone/tile
    }
    hasBeenVisited = 1;
}

void NextTile::moveToNextTile(World& currentTile, std::string tileSelection) {
    //this->equals(currentTile);  //this could lead somewhere

    /*if(actionsToAdvanceTile.find(tileSelection) != actionsToAdvanceTile.end()){
        World nextTile = actionsToAdvanceTile[tileSelection];
        currentTile = nextTile;
    }
    else{
        std::cout << "Invalid action. Try again." << std::endl; 
    }*/
}