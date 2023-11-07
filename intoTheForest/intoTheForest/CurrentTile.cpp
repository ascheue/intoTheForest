#include "World.h"
#include "CurrentTile.h"
#include "StartingTile.h"
#include <iostream>

CurrentTile::CurrentTile() {
    tileName = "nullTile";
    tileID = -1;
    numAdjacents = 0;
    numNavigations = 0;
    //listOfAdjacents = std::vector<World>();
    //listOfNavigations = std::vector<std::string>();

    listOfNavigations.push_back("");
    listOfNavigations.push_back("");
    listOfNavigations.push_back("");
    listOfNavigations.push_back("");
    listOfNavigations.push_back("");

    welcomeMessage = "error: CurrentTile Welcome messsage";
    revisitMessage = "error: CurrentTile revisit message";

    isCurrentLevel = 0; //may not need
    hasBeenVisited = 0;
}

void CurrentTile::displayText() {
    if(!hasBeenVisited){
        std::cout << welcomeMessage << std::endl;
    }
    else if(hasBeenVisited){
        std::cout << revisitMessage << std::endl;
    }
    hasBeenVisited = 1;
}

void CurrentTile::moveToNextTile(World& yourCurrentTile, std::string tileSelection) {

}


