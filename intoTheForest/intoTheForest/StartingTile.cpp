#include "World.h"
#include "StartingTile.h"
#include "CurrentTile.h"
#include "Tile1A.h"
#include "Tile1B.h"
#include "Tile1C.h"
#include <iostream>

StartingTile::StartingTile() {
    tileName = "StartingTile";
    tileID = 0;
    numAdjacents = 0;
    numNavigations = 3;
    //listOfAdjacents = std::vector<World>();
    //listOfNavigations = std::vector<std::string>();

    listOfNavigations.push_back("go left");
    pathIsClear.push_back(true);
    listOfNavigations.push_back("go straight");
    pathIsClear.push_back(true);
    listOfNavigations.push_back("go right");
    pathIsClear.push_back(true);
    listOfNavigations.push_back("");
    pathIsClear.push_back(true);
    listOfNavigations.push_back("");
    pathIsClear.push_back(true);

    welcomeMessage = "Welcome to the Starting Tile";
    revisitMessage = "You are back at the starting tile";

    isCurrentLevel = 1; //may not need
    hasBeenVisited = 0;
}

World StartingTile::moveToNextTile(std::string tileSelection) {
    Tile1A tile1a;
    Tile1B tile1b;
    Tile1C tile1c;
    StartingTile startingTile;
    if(tileSelection == listOfNavigations[0]){
        if(pathIsClear[0]) {return tile1a;}
        else{std::cout << "You must clear the path first!" << std::endl;}
        return startingTile;
    }
    else if(tileSelection == listOfNavigations[1]){
        if(pathIsClear[1]) {return tile1b;}
        else{std::cout << "You must clear the path first!" << std::endl;}
        return startingTile;
    }
    else if(tileSelection == listOfNavigations[2]){
        if(pathIsClear[2]) {return tile1c;}
        else{std::cout << "You must clear the path first!" << std::endl;}
        return startingTile;
    }
    else{
        std::cout << "Selection Not Found!!" << std::endl;
        return startingTile;
    }
}


