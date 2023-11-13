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
    pathIsClear.push_back(true);
    listOfNavigations.push_back("");
    pathIsClear.push_back(true);
    listOfNavigations.push_back("");
    pathIsClear.push_back(true);
    listOfNavigations.push_back("");
    pathIsClear.push_back(true);
    listOfNavigations.push_back("");
    pathIsClear.push_back(true);
    
    welcomeMessage = "Welcome to Tile1B.  What would you like to do?\n[wait]\n[leave]";
    revisitMessage = "You are back at Tile1B.  What would you like to do?\n[wait]\n[leave]";
    navMessage = "[go back]";

    isCurrentLevel = 1; //may not need
    hasBeenVisited = 0;
}

World Tile1B::moveToNextTile(std::string tileSelection) {
    StartingTile startingTile;
    Tile1B tile1b;
    if(tileSelection == listOfNavigations[0]){
        if(pathIsClear[0]) {return startingTile;}
        else{std::cout << "You must clear the path first!" << std::endl;}
        return tile1b;
    }
    else{
        std::cout << "Selection Not Found!!" << std::endl;
        return tile1b;
    }
}


