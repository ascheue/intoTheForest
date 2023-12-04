#include "Player.h"
#include "Logger.h"
#include "ArmorFactory.cpp"
//#include "Vendor.h"
#include <iostream>

Logger* logger1 = Logger::getInstance();

Player::Player() {
    playerClass = "";
    playerHealth = 100;
    defenseStat = 0;
    attackStat = 0;
    wallet = 15;
    inventorySize = 5;
    busyOnTile = true;

    inventory.push_back("healthPotion");
    sellingPrices.push_back(5);
    inventory.push_back("");
    sellingPrices.push_back(0);
    inventory.push_back("");
    sellingPrices.push_back(0);
    inventory.push_back("");
    sellingPrices.push_back(0);
    inventory.push_back("");
    sellingPrices.push_back(0);
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
    std::cout << "--------------------------------------------" << std::endl;
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
//MB updated wait function description. 
void Player::setNextMove(std::string move) {
    nextMove = move;
    if(move == "wait") {std::cout << "You whistle a merry tune and relax for a moment, but all too soon it's time to go." << std::endl;}
    else if(move == "inventory") {displayInventoryForItemUse();}
    else if(move == "leave") {busyOnTile = false;}
    //do we need the player.currentlyEngaged var??
    //below can be the args for any misc tiles with additional commands

}

void Player::addToInventory(std::string item) {
    for(int i=0;i<inventorySize;i++){
        if(inventory[i] == ""){
            inventory[i] = item;
            return;
        }
    }
    inventory.push_back(item);
}

int Player::addToInventoryAndReturnSlot(std::string item) {
    for(int i=0;i<inventorySize;i++){
        if(inventory[i] == ""){
            inventory[i] = item;
            return i;
        }
    }
    inventory.push_back(item);
}

void Player::removeFromInventory(std::string item) {
    for(int i=0; i<inventorySize; i++){
        if(inventory[i] == item){
            inventory[i] = "";
            return;
        }
    }
    std::cout <<"removeFromInventory could not find " << item << " in inventory!!" << std::endl;
}

bool Player::containsInInventory(std::string item) {
    for(int i=0;i<inventorySize;i++){
        if(inventory[i] == item) {return true;}
    }
    return false;
}

int Player::returnInventorySlot(std::string item) {
    for(int i=0;i<inventorySize;i++){
        if(inventory[i] == item) {return i;}
    }
    std::cout << "item not found in inventory!1" << std::endl;
    return -1;                                                      //this causes an out of bounds error becasue it attempts to access [-1]
}

void Player::sellItem(std::string item) {
    for(int i=0; i<inventorySize; i++){
        if(inventory[i] == item){
            inventory[i] = "";
            addToWallet(sellingPrices[i]);
            return;
        }
    }
    std::cout << "sellItem could not find " << item << " in inventory!!2" << std::endl;
}

int Player::sellItemAndReturnSlot(std::string item) {           //can we get rid of this function?
    for(int i=0; i<inventorySize; i++){
        if(inventory[i] == item){
            inventory[i] = "";
            addToWallet(sellingPrices[i]);
            //sellingPrices[i] = 0;
            return i;
        }
        std::cout << "sellItem could not find " << item << " in inventory!!2" << std::endl;
    }
}

void Player::displayInventory() {
    std::cout << "Player Inventory: " << std::endl;
    for(int i=0;i<inventorySize;i++){
        std::cout << "-" << inventory[i] << " " << sellingPrices[i] << std::endl;
    }
    std::cout << "Player Wallet: $" << getWallet() << std::endl;
}

void Player::useItem(std::string item) {
    if(item == "healthPotion" && containsInInventory("healthPotion")) {
        int temp = playerHealth;
        useHealthPotion25();
        sellingPrices[returnInventorySlot(item)] = 0;
        inventory[returnInventorySlot(item)] = "";
        std::cout << "You use your potion to heal from " << temp << " to " << playerHealth << std::endl;
    }
    else if(item == "magic scroll" && containsInInventory("magic scroll")) {std::cout << "Cannot use that item here!" << std::endl;}
    else if(item == "key to the kingdom" && containsInInventory("key to the kingdom")) {std::cout << "Cannot use that item here!" << std::endl;}
    else if(item == "pickaxe") {std::cout << "This item could be useful for something..." << std::endl;}

    else {std::cout << "you wanna use what?" << std::endl;}
}

void Player::displayInventoryForItemUse() {
    bool busy = true;
    while(busy){
        std::cout << "Player Inventory: " << std::endl;
        for(int i=0;i<inventorySize;i++){
            std::cout << "-" << inventory[i] << " " << sellingPrices[i] << std::endl;
        }
        std::cout << "Player Wallet: $" << getWallet() << std::endl;

        std::cout << "Select and item or [close] bag" << std::endl;
        std::string input = gatherUserInput();
        if(containsInInventory(input)) {useItem(input);}
        if(input == "close") {busy = false;}
    }
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

int Player::getInventorySize() {
    try{
        return inventorySize;
    }
    catch(std::exception& e) {
        logger1->log("getInventorySize returned something bad: " + std::string(e.what()));
    }
}

void Player::setInventorySize(int size) {
    inventorySize = size;
}



void Player::useHealthPotion25() {
    playerHealth = playerHealth + 25;
    if(playerHealth >= 100) {playerHealth = 100;}
}

void Player::displayPlayerCombatPrompt() {
    std::cout << "Player's Turn: What would you like to do\n[attack]\n[inventory]\n[flee]" << std::endl;
}