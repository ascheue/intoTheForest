#include "World.h"
#include "StartingTile.h"
#include "CurrentTile.h"
#include <iostream>

StartingTile::StartingTile() {
    tileName = "StartingTile";
    tileID = 0;
    numAdjacents = 0;
    numNavigations = 3;
    //listOfAdjacents = std::vector<World>();
    //listOfNavigations = std::vector<std::string>();

    listOfNavigations.push_back("go left");
    listOfNavigations.push_back("go straight");
    listOfNavigations.push_back("go right");
    listOfNavigations.push_back("");
    listOfNavigations.push_back("");

    welcomeMessage = "Welcome to the Starting Tile";
    revisitMessage = "You are back at the starting tile";

    isCurrentLevel = 1; //may not need
    hasBeenVisited = 0;
}

void StartingTile::displayText() {
    if(!hasBeenVisited){
        std::cout << welcomeMessage << std::endl;
    }
    else if(hasBeenVisited){
        std::cout << revisitMessage << std::endl;
    }
    hasBeenVisited = 1;
}

void StartingTile::moveToNextTile(World& yourCurrentTile, std::string tileSelection) {

}


