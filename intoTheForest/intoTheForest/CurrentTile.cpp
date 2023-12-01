#include "World.h"
#include "CurrentTile.h"
#include "StartingTile.h"
#include "Player.h"
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
    navMessage = "error: currentTile does not have any navigations";

    isCurrentLevel = 0; //may not need
    hasBeenVisited = 0;
}

std::string CurrentTile::gatherUserInput() {
    std::string response;
//MB fixed typo in output
    std::cout << "Error: CurrentTile shouldn't be asking what you want to do ";
    std::getline(std::cin, response);
    return response;
}

World CurrentTile::moveToNextTile(std::string tileSelection) {
    CurrentTile currentTile;
    return currentTile;
}

void CurrentTile::setNextAction(std::string action) {
    Player player;
    nextAction = action;
    if(action == "wait") {std::cout << "Your character waits in place, fun0" << std::endl;}
    else if(action == "leave") {player.setIsBusy(false);}
    else if(action == "approach") {player.setIsEngaged(true);}
    else {std::cout << "Selection Not Found!4" << std::endl;}
}


