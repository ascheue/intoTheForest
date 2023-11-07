#include "World.h"
#include "DataModule.h"
#include "Logger.h"
#include "StartingTile.h"
#include "CurrentTile.h"
#include <iostream>

Logger* logger = Logger::getInstance();

//Constructor
World::World() {

}

void World::displayText() {
    //Welcome!!!
}

std::string World::gatherUserInput() {

    std::string response;

    std::cout << "Where would you like to go? ";
    std::getline(std::cin, response);
    logger->log("User has chosen: " + response);
    return response;
}

World World::getCurrentWorld() {
    World newWorld;
    try{
        return newWorld;
    }
    catch(std::exception& e){
        logger->log("getCurrentWorld returned something bad: " + std::string(e.what()));
    }
}

int World::getCurrentTileID() {
    try{
        return tileID;
    }
    catch(std::exception& e) {
        logger->log("getCurrentTileID returned something bad: " + std::string(e.what()));
    }
}

std::string World::getCurrentTileName() {
    try{
        return tileName;
    }
    catch(std::exception& e) {
        logger->log("getCurrentNameID returned something bad: " + std::string(e.what()));
    }
}

bool World::tileIsAdjacent(World tile) {
    return false;
}

void World::equals(const World& otherWorld) {
    tileName = otherWorld.tileName;
    tileID = otherWorld.tileID;
    numAdjacents = otherWorld.numAdjacents;
    //actionsToAdvanceTile = otherWorld.actionsToAdvanceTile;
    listOfNavigations = otherWorld.listOfNavigations;
    isCurrentLevel = otherWorld.isCurrentLevel;
    hasBeenVisited = otherWorld.hasBeenVisited;
    welcomeMessage = otherWorld.welcomeMessage;
    revisitMessage = otherWorld.revisitMessage;
}

void World::moveToNextTile(World& currentTile, std::string tileSelection) {}

