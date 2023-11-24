#include "World.h"
#include "StartingTile.h"
#include "CurrentTile.h"
#include "Tile1A.h"
#include "Tile1B.h"
#include "Tile1C.h"
#include "Player.h"
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

    welcomeMessage = "Welcome to the Starting Tile.  What would you like to do?\n[wait]\n[inventory]\n[leave]";
    revisitMessage = "You are back at the starting tile.  What would you like to do?\n[wait]\n[inventory]\n[leave]";
    navMessage = "[go left]\n[go straight]\n[go right]";

    isCurrentLevel = 1; //may not need
    hasBeenVisited = 0;
}

std::string StartingTile::gatherUserInput() {
    std::string response;

    std::cout << "What would you like to do?" << std::endl;
    std::cout << "[leave]" << std::endl;
    std::getline(std::cin, response);
    return response;
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

void StartingTile::setNextAction(std::string action) {  //this function is never called, same with other tiles
    Player player;
    nextAction = action;
    if(action == "wait") {std::cout << "Your character waits in place, fun3" << std::endl;}
    else if(action == "leave") {player.setIsBusy(false);}
    else if(action == "approach") {player.setIsEngaged(true);}
    else {std::cout << "Selection Not Found!4" << std::endl;}
}
 

