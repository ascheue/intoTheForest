#include "World.h"
#include "NextTile.h"
#include "StartingTile.h"
#include "CurrentTile.h"
#include "PreviousTile.h"
#include <iostream>

//CurrentTile otherTile1;
//NextTile nextTile;

//Constructor
PreviousTile::PreviousTile() {
    //locationEnum = startingTile;
    tileName = "PreviousTile";
    tileID = -2;
    numAdjacents = 0;
    numNavigations = 0;
    //listOfAdjacents = std::vector<World>();
    //listOfNavigations = std::vector<std::string>();

    //listOfAdjacents.push_back(otherTile1);    //this line specifically is causing issues
    //listOfAdjacents[0] = otherTile1;

    //listOfNavigations.push_back("go back");
    //listOfNavigations[0] = "go back";

    //actionsToAdvanceTile["go straight"] = nextTile;    //testing this
    //actionsToAdvanceTile["go forward"] = NextTile();

    isCurrentLevel = 1; //may not need
    hasBeenVisited = 1;
}

void PreviousTile::displayText() {
    if(!hasBeenVisited){
        //Message for the first time you have entered zone/tile
    }
    else if(hasBeenVisited){
        //Message for already having been to this zone/tile
    }
    hasBeenVisited = 1;
}

void PreviousTile::moveToNextTile(World& yourCurrentTile, std::string tileSelection) {
    if(actionsToAdvanceTile.find(tileSelection) != actionsToAdvanceTile.end()){
        World nextTile = actionsToAdvanceTile[tileSelection];
        yourCurrentTile = nextTile;
    }
    else{
        std::cout << "Invalid action. Try again." << std::endl; 
    }
}


