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
    pathIsClear.push_back(true);
    listOfNavigations.push_back("");
    pathIsClear.push_back(true);
    listOfNavigations.push_back("");
    pathIsClear.push_back(true);
    listOfNavigations.push_back("");
    pathIsClear.push_back(true);
    listOfNavigations.push_back("");
    pathIsClear.push_back(true);

    welcomeMessage = "Welcome to Tile1A";
    revisitMessage = "You are back at Tile1A";

    isCurrentLevel = 1; //may not need
    hasBeenVisited = 0;
}

World Tile1A::moveToNextTile(std::string tileSelection) {
    StartingTile startingTile;
    Tile1A tile1a;
    if(tileSelection == listOfNavigations[0]){
        if(pathIsClear[0]) {return startingTile;}
        else{std::cout << "You must clear the path first!" << std::endl;}
        return tile1a;
    }
    else{
        std::cout << "Selection Not Found!!" << std::endl;
        return tile1a;
    }
}


