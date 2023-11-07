#include "World.h"
#include "StartingTile.h"
#include "CurrentTile.h"
#include "Tile1B.h"
#include <iostream>

Tile1B::Tile1B() {
    tileName = "Tile1B";
    tileID = 2;
    numAdjacents = 1;
    numNavigations = 1;
    //listOfAdjacents = std::vector<World>();
    //listOfNavigations = std::vector<std::string>();

    listOfNavigations.push_back("go back");
    listOfNavigations.push_back("");
    listOfNavigations.push_back("");
    listOfNavigations.push_back("");
    listOfNavigations.push_back("");
    
    welcomeMessage = "Welcome to Tile1B";
    revisitMessage = "You are back at Tile1B";

    isCurrentLevel = 1; //may not need
    hasBeenVisited = 0;
}

void Tile1B::displayText() {
    if(!hasBeenVisited){
        std::cout << welcomeMessage << std::endl;
    }
    else if(hasBeenVisited){
        std::cout << revisitMessage << std::endl;
    }
    hasBeenVisited = 1;
}

void Tile1B::moveToNextTile(World& yourCurrentTile, std::string tileSelection) {

}


