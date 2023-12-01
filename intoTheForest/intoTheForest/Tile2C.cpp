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
    //MB Updated messages
    welcomeMessage = "You've successfully cleared the path of rocks!\nYou proceed forward, happy to be on your way.\n Your excitement soon fades when you find the path blocked yet again...by a bandit.\nYou won't be able to get through without dealing with him.\nWhat would you like to do?\n[interact]\n[wait]\n[inventory]\n[leave]";
    creatureDeadMessage = "You don't have anywhere to be, so you return to the bandit's resting place.\nWhat would you like to do?\n[wait]\n[leave]\n[inventory]\n[examine] the body";
    revisitMessage = "The bandit is still there. Apparently they teach 'patience is a virtue' in bandit school.\nWhat would you like to do?\n[interact]\n[wait]\n[inventory]\n[leave]";
    navMessage = "[go back] to the junction in the path";

    isCurrentLevel = 1; //may not need
    hasBeenVisited = 0;
}

void Tile2C::displayText(Creature& creature) {
    if(!hasBeenVisited){
        std::cout << welcomeMessage << std::endl;
    }
    else if(hasBeenVisited){
        if(creature.getHealth()<=0) {std::cout << creatureDeadMessage << std::endl;}
        else {std::cout << revisitMessage << std::endl;}
    }
    hasBeenVisited = 1;
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


