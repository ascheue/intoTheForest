#include "Player.h"
#include "Logger.h"
#include "ArmorFactory.cpp"
#include <iostream>

Logger* logger1 = Logger::getInstance();

Player::Player() {
    playerClass = "";
    playerHealth = 100;
    defenseStat = 0;
    attackStat = 0;
    wallet = 25;
    inventorySize = 5;
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

int Player::getWallet() {
    try{
        return wallet;
    }
    catch(std::exception& e) {
        logger1->log("getWallet returned something bad: " + std::string(e.what()));
    }
}

void Player::setWallet(int money) {
    wallet = money;
}

void Player::addToWallet(int addition){
    wallet = wallet + addition;
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

void Player::addToInventory(std::string item) {
    for(int i=0;i<sizeof(inventory);i++){
        if(inventory[i] == ""){
            inventory[i] = item;
            return;
        }
    }
    inventory.push_back(item);
}

bool Player::containsInInventory(std::string item) {
    for(int i=0;i<inventorySize;i++){
        if(inventory[i] == item) {return true;}
    }
    return false;
}

int Player::getPlayerHealth() {
    try{
        return playerHealth;
    }
    catch(std::exception& e) {
        logger1->log("getPlayerHealth returned something bad: " + std::string(e.what()));
    }
}

void Player::setPlayerHealth(int health) {
    playerHealth = health;
}

std::string Player::getPlayerClass() {
    try{
        return playerClass;
    }
    catch(std::exception& e) {
        logger1->log("getPlayerClass returned something bad: " + std::string(e.what()));
    }
}

void Player::setPlayerClass(std::string newClass) {
    playerClass = newClass;
}