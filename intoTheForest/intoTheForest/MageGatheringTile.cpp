// MageGatheringTile.cpp
#include "MageGatheringTile.h"
#include "StartingTile.h"
#include "World.h"
#include "CurrentTile.h"
#include <iostream>

MageGatheringTile::MageGatheringTile() {
    tileName = "MageGatheringTile";
    tileID = 3;
    numAdjacents = 1;
    numNavigations = 1;

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

    welcomeMessage = "Welcome to MageGatheringTile. You see a mystical object. What would you like to do?\n[gather]\n[leave]\n[interact]";
    revisitMessage = "You are back at MageGatheringTile. The mystical object awaits. What would you like to do?\n[wait]\n[leave]\n[interact]";
    navMessage = "[go back]";

    isCurrentLevel = 1;
    hasBeenVisited = 0;
}

World MageGatheringTile::moveToNextTile(std::string tileSelection) {
    StartingTile startingTile;
    MageGatheringTile mageGatheringTile;

    if (tileSelection == listOfNavigations[0]) {
        if (pathIsClear[0]) {
            std::cout << "You gathered a mystical object. Well done!" << std::endl;
            // Perform actions related to gathering the object for the Mage
            return startingTile;
        }
        else {
            std::cout << "You must clear the path first!" << std::endl;
            return mageGatheringTile; // Returning the same tile because the path is not clear
        }
    }
    else {
        std::cout << "Selection Not Found!!" << std::endl;
        return mageGatheringTile; //Returning the same tile for unknown selection
    }
}


