#include "World.h"
#include "StartingTile.h"
#include "CurrentTile.h"
#include "Tile1C.h"
#include <iostream>

Tile1C::Tile1C() {
    tileName = "Tile1C";
    tileID = 3;
    numAdjacents = 1;
    numNavigations = 1;
    //listOfAdjacents = std::vector<World>();
    //listOfNavigations = std::vector<std::string>();

    listOfNavigations.push_back("go back");
    listOfNavigations.push_back("");
    listOfNavigations.push_back("");
    listOfNavigations.push_back("");
    listOfNavigations.push_back("");

    welcomeMessage = "Welcome to Tile1C";
    revisitMessage = "You are back at Tile1C";

    isCurrentLevel = 1; //may not need
    hasBeenVisited = 0;
}

void Tile1C::displayText() {
    if(!hasBeenVisited){
        std::cout << welcomeMessage << std::endl;
    }
    else if(hasBeenVisited){
        std::cout << revisitMessage << std::endl;
    }
    hasBeenVisited = 1;
}

void Tile1C::moveToNextTile(World& yourCurrentTile, std::string tileSelection) {}


