#include "World.h"
#include "StartingTile.h"
#include "CurrentTile.h"
#include "Tile1A.h"
#include "Player.h"
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
    //MB updated messages 
    welcomeMessage = "The path opens up to a small clearing.\nThere is an old traveling salesman standing by a cart nearby.\nHe appears to be selling various wares.\nWhat would you like to do?\n[wait]\n[approach] the old man\n[inventory]\n[leave]";
    revisitMessage = "The old man is waiting patiently. What would you like to do?\n[wait]\n[approach] the cart\n[inventory]\n[leave]";
    navMessage = "[go back] to the junction in the path";

    isCurrentLevel = 1; //may not need
    hasBeenVisited = 0;
}

std::string Tile1A::gatherUserInput() {
    std::string response;

    std::cout << "What would you like to do?" << std::endl;
    std::cout << "[leave]" << std::endl;
    std::getline(std::cin, response);
    return response;
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

void Tile1A::setNextAction(std::string action) {
    Player player;
    nextAction = action;
    if(action == "wait") {std::cout << "Your character waits in place, fun1" << std::endl;}
    else if(action == "leave") {player.setIsBusy(false);}
    else if(action == "approach") {player.setIsEngaged(true);}
    else {std::cout << "Selection Not Found!4" << std::endl;}
}

std::string Tile1A::getNextAction() {
    return nextAction;
}

