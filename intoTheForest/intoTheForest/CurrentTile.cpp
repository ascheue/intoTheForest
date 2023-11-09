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
    pathIsClear.push_back(true);
    listOfNavigations.push_back("");
    pathIsClear.push_back(true);
    listOfNavigations.push_back("");
    pathIsClear.push_back(true);
    listOfNavigations.push_back("");
    pathIsClear.push_back(true);
    listOfNavigations.push_back("");
    pathIsClear.push_back(true);

    welcomeMessage = "error: CurrentTile Welcome messsage";
    revisitMessage = "error: CurrentTile revisit message";

    isCurrentLevel = 0; //may not need
    hasBeenVisited = 0;
}

World CurrentTile::moveToNextTile(std::string tileSelection) {
    CurrentTile currentTile;
    return currentTile;
}


