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

    welcomeMessage = "As you head down the path, the rockslide in the distance grows closer.\nIt is soon apparent that you won't be able to traverse the pathway.\nThe way straight ahead is completely blocked.\nIf only you had some sort of tool?\nWhat would you like to do?\n[wait]\n[inventory]\n[leave]";
    welcomeMessageWithPickaxe = "As you head down the path, the rockslide in the distance grows closer.\nIt is soon apparent that you won't be able to traverse the pathway.\nThe way straight ahead is completely blocked.\nIt looks like you could use your pickaxe to get through.\nWhat would you like to do?\n[use pickaxe]\n[wait]\n[inventory]\n[leave]";
    revisitMessage = "You're glad you weren't here when all the rocks fell!\nWhat would you like to do?\n[wait]\n[inventory]\n[leave]";
    revisitMessageWithPickaxe = "You're glad you weren't here when all the rocks fell!\nLucky for you, you have a pickaxe that might help.\nWhat would you like to do?\n[wait]\n[inventory]\n[leave]";
    revisitMessageWhenPathClear = "You kick a rock as you pass by the rockslide.\nRevenge for your sore arms.\nWhat would you like to do?\n[wait]\n[inventory]\n[leave]";

    navMessage = "[go straight] forward\n[go back] down the path";

    isCurrentLevel = 1; //may not need
    hasBeenVisited = 0;
}

void Tile1C::displayText(Player& player) {
    if(pathIsClear[1]) {
        std::cout << revisitMessageWhenPathClear << std::endl;
    }
    else {
        if(!hasBeenVisited){
            if(player.containsInInventory("pickaxe")) {std::cout << welcomeMessageWithPickaxe << std::endl;}
            else {std::cout << welcomeMessage << std::endl;}
        }
        else if(hasBeenVisited){
            if(player.containsInInventory("pickaxe")) {std::cout << revisitMessageWithPickaxe << std::endl;}
            else {std::cout << revisitMessage << std::endl;}
        }
    }
    hasBeenVisited = 1;
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


