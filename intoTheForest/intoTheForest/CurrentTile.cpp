#include "World.h"
#include "CurrentTile.h"
#include "StartingTile.h"
#include "NextTile.h"
#include <iostream>

//StartingTile startingTile;
//NextTile nextTile;

//Constructor
CurrentTile::CurrentTile() {
    //locationEnum = OOB;
    tileName = "nullTile";
    tileID = -1;
    numAdjacents = 0;
    numNavigations = 0;
    //listOfAdjacents = std::vector<World>();
    //listOfNavigations = std::vector<std::string>();

    //listOfAdjacents.push_back(otherTile);
    //listOfAdjacents[0] = otherTile;

    //listOfNavigations.push_back("go straight");
    //listOfNavigations[0] = "go straight";

    //actionsToAdvanceTile["go back"] = World(startingTile);

    isCurrentLevel = 0; //may not need
    hasBeenVisited = 0;
}

void CurrentTile::displayText() {
    if(!hasBeenVisited){
        //Message for the first time you have entered zone/tile
    }
    else if(hasBeenVisited){
        //Message for already having been to this zone/tile
    }
    hasBeenVisited = 1;
}

void CurrentTile::moveToNextTile(World& yourCurrentTile, std::string tileSelection) {
    //switch(tileSelection)
    
    
    
    //this->equals(currentTile);  //this could lead somewhere

    if(actionsToAdvanceTile.find(tileSelection) != actionsToAdvanceTile.end()){
        World nextTile = actionsToAdvanceTile[tileSelection];
        yourCurrentTile.equals(nextTile);
    }
    else{
        std::cout << "Invalid action. Try again." << std::endl; 
    }
}


