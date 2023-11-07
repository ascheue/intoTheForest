#include "World.h"
#include "StartingTile.h"
#include "CurrentTile.h"
#include "Tile1A.h"
#include <iostream>

Tile1A::Tile1A() {
    tileName = "Tile1A";
    tileID = 1;
    numAdjacents = 1;
    numNavigations = 1;
    //listOfAdjacents = std::vector<World>();
    //listOfNavigations = std::vector<std::string>();

    listOfNavigations.push_back("go back");
    listOfNavigations.push_back("");
    listOfNavigations.push_back("");
    listOfNavigations.push_back("");
    listOfNavigations.push_back("");

    welcomeMessage = "Welcome to Tile1A";
    revisitMessage = "You are back at Tile1A";

    isCurrentLevel = 1; //may not need
    hasBeenVisited = 0;
}

void Tile1A::displayText() {
    if(!hasBeenVisited){
        std::cout << welcomeMessage << std::endl;
    }
    else if(hasBeenVisited){
        std::cout << revisitMessage << std::endl;
    }
    hasBeenVisited = 1;
}

void Tile1A::moveToNextTile(World& yourCurrentTile, std::string tileSelection) {

}


