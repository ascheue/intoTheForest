#include "World.h"
#include "StartingTile.h"
#include "CurrentTile.h"
#include "Tile1C.h"
#include "Tile2C.h"
#include <iostream>

Tile2C::Tile2C() {
    tileName = "Tile2C";
    tileID = 4;
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

    welcomeMessage = "You successfully clear the path to Tile2C.  What would you like to do?\n[wait]\n[leave]";
    revisitMessage = "You are back at Tile2C.  What would you like to do?\n[wait]\n[leave]";
    navMessage = "[go back]";

    isCurrentLevel = 1; //may not need
    hasBeenVisited = 0;
}
/*
void Tile1C::clearPathForward(int i) {
    pathIsClear[i] = true;
}
*/
World Tile2C::moveToNextTile(std::string tileSelection) {
    Tile2C tile2c;
    Tile1C tile1c;
    if(tileSelection == listOfNavigations[0]){
        if(pathIsClear[0]) {return tile1c;}
        else{std::cout << "You must clear the path first!" << std::endl;}
        return tile2c;
    }
    else{
        std::cout << "Selection Not Found!!" << std::endl;
        return tile2c;
    }
}


