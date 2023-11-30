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
    
    welcomeMessage = "Welcome to Tile1B.  What would you like to do?\n[wait]\n[leave]\n[inventory]\n[interact] with the creature";
    creatureDeadMessage = "You are back at Tile1B.  What would you like to do?\n[wait]\n[leave]\n[inventory]\n[examine] the body";
    revisitMessage = "You are back at Tile1B.  What would you like to do?\n[wait]\n[leave]\n[inventory]\n[interact] with the creature";
    navMessage = "[go back]";

    isCurrentLevel = 1; //may not need
    hasBeenVisited = 0;
}

void Tile1B::displayText(Creature& creature) {
    if(!hasBeenVisited){
        std::cout << welcomeMessage << std::endl;
    }
    else if(hasBeenVisited){
        if(creature.getHealth()<=0) {std::cout << creatureDeadMessage << std::endl;}
        else {std::cout << revisitMessage << std::endl;}
    }
    hasBeenVisited = 1;
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


