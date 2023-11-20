#include "World.h"
#include "StartingTile.h"
#include "CurrentTile.h"
#include "Tile1C.h"
#include "Tile2C.h"
#include <iostream>

Tile1C::Tile1C() {
    tileName = "Tile1C";
    tileID = 3;
    numAdjacents = 2;
    numNavigations = 2;
    //listOfAdjacents = std::vector<World>();
    //listOfNavigations = std::vector<std::string>();

    listOfNavigations.push_back("go back");
    pathIsClear.push_back(true);
    listOfNavigations.push_back("go straight");
    pathIsClear.push_back(false);
    listOfNavigations.push_back("");
    pathIsClear.push_back(true);
    listOfNavigations.push_back("");
    pathIsClear.push_back(true);
    listOfNavigations.push_back("");
    pathIsClear.push_back(true);

    welcomeMessage = "Welcome to Tile1C.  What would you like to do?\n[wait]\n[leave]";
    revisitMessage = "You are back at Tile1C.  What would you like to do?\n[wait]\n[leave]";
    navMessage = "[go straight]\n[go back]";

    isCurrentLevel = 1; //may not need
    hasBeenVisited = 0;
}

void Tile1C::clearPathForward(int i) {
    pathIsClear[i] = true;
}

World Tile1C::moveToNextTile(std::string tileSelection) {
    StartingTile startingTile;
    Tile1C tile1c;
    Tile2C tile2c;
    if(tileSelection == listOfNavigations[0]){
        if(pathIsClear[0]) {return startingTile;}
        else{std::cout << "You must clear the path first!" << std::endl;}
        return tile1c;
    }
    else if(tileSelection == listOfNavigations[1]){
        if(pathIsClear[1]) {return tile2c;} 
        else{std::cout << "You must clear the path first!" << std::endl;}
        return tile1c;
    }
    else{
        std::cout << "Selection Not Found!!" << std::endl;
        return tile1c;
    }
}


