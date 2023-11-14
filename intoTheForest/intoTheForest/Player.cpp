#include "Player.h"
#include "Logger.h"
#include "ArmorFactory.cpp"
#include <iostream>

Logger* logger1 = Logger::getInstance();

Player::Player() {
    playerHealth = 100;
    defenseStat = 0;
    attackStat = 0;
    busyOnTile = true;

    inventory.push_back("");
    inventory.push_back("");
    inventory.push_back("");
    inventory.push_back("");
    inventory.push_back("");
}

void Player::characterSelectionPrompt() {
    std::cout << "Please select a player class\n[Warrior]\n[Mage]\n[Ranger]" << std::endl;
}

bool Player::getIsBusy() {
    try{
        return busyOnTile;
    }
    catch(std::exception& e) {
        logger1->log("getIsBusy returned something bad: " + std::string(e.what()));
    }
}

void Player::setIsBusy(bool busy) {
    busyOnTile = busy;
}

std::string Player::gatherUserInput() {
    std::string response;

    std::cout << ">> ";
    std::getline(std::cin, response);
    logger1->log("User has chosen: " + response);
    return response;
}

std::string Player::getNextMove() {
    try{
        return nextMove;
    }
    catch(std::exception& e) {
        logger1->log("NextMove returned something bad: " + std::string(e.what()));
    }
}

bool Player::getIsEngaged() {
    try{
        return currentlyEngaged;
    }
    catch(std::exception& e) {
        logger1->log("getIsEngaged returned something bad: " + std::string(e.what()));
    }
}

void Player::setIsEngaged(bool engaged) {
    currentlyEngaged = engaged;
}

void Player::setNextMove(std::string move) {
    nextMove = move;
    if(move == "wait") {std::cout << "Your character waits in place, fun2" << std::endl;}
    else if(move == "leave") {busyOnTile = false;}
    //else if(move == "approach") {currentlyEngaged = true;} //CAREFUL!! this variable is never reset!!!
    //else {std::cout << "Selection Not Found!4" << std::endl;}
}