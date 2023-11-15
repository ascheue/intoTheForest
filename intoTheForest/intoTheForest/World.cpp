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
    if(!hasBeenVisited){
        std::cout << welcomeMessage << std::endl;
    }
    else if(hasBeenVisited){
        std::cout << revisitMessage << std::endl;
    }
    hasBeenVisited = 1;
}

std::string World::gatherUserInput() {

    std::string response;

    //std::cout << "Where would you like to go? " << std::endl;
    std::cout << ">> ";
    std::getline(std::cin, response);
    logger->log("User has chosen: " + response);
    return response;
}

World World::getCurrentWorld() {    //does not currently work
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

int World::getNumAdjacents() {
    try{
        return numAdjacents;
    }
    catch(std::exception& e) {
        logger->log("getNumAdjacents returned something bad: " + std::string(e.what()));
    }
}

int World::getNumNavigations() {
    try{
        return numNavigations;
    }
    catch(std::exception& e) {
        logger->log("getNumNavigations returned something bad: " + std::string(e.what()));
    }
}

std::string World::getNavigation(int i) {
    try{
        return listOfNavigations[i];
    }
    catch(std::exception& e) {
        logger->log("getNavigation returned something bad: " + std::string(e.what()));
    }
}

std::string World::getNextMove() {
    try{
        return nextAction;
    }
    catch(std::exception& e) {
        logger->log("NextMove returned something bad: " + std::string(e.what()));
    }
}

void World::setNextMove(std::string move) {
    nextAction = move;
}

bool World::isPathClear(int i) {
    try{
        return pathIsClear[i];
    }
    catch(std::exception& e) {
        logger->log("isPathClear returned something bad: " + std::string(e.what()));
    }
}

void World::clearPathForward(int i) {
    pathIsClear[i] = true;
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
    pathIsClear = otherWorld.pathIsClear;
    isCurrentLevel = otherWorld.isCurrentLevel;
    hasBeenVisited = otherWorld.hasBeenVisited;
    welcomeMessage = otherWorld.welcomeMessage;
    revisitMessage = otherWorld.revisitMessage;
    navMessage = otherWorld.navMessage;
}

World World::moveToNextTile(std::string tileSelection) {
    World world;
    return world;
}

void World::setNextAction(std::string action) {
    nextAction = action;
}

std::string World::getNextAction() {
    return nextAction;
}
