#include "NonCutes.h"
#include "Logger.h"
#include "Player.h"
#include <iostream>



NonCutes::NonCutes() {
    health = 25;
    attackStat = 3;
    defenseStat = 3;
    skinValue = 15;
    isSkinned = false;
}
//MB updated interactions
//MB added case functionality to if
void NonCutes::interact(Player &player) {
    if(health == 0) {examineBody(player);}
    else {
        bool isSelecting = true;
        while(isSelecting) {
            std::cout << "The creature hisses again and snaps at your fingers! What will you do?\n[flee]\n[fight]" << std::endl;
            std::string response = player.gatherUserInput();
            if(response == "fight" || response == "Fight") {
                engageInCombat(player);
                isSelecting = false;
            }
            else if (response == "flee" || response == "Flee") {
                std::cout << "You successfully escape the creature" << std::endl;
                isSelecting = false;
            }
            else { 
                std::cout << "Fortunately, the creature pauses to let you compose yourself." << std::endl; 
            }
        }
    }
}

/*This function is a WIP!!!!  -ascheuer*/
void NonCutes::engageInCombat(Player& player) {
    std::cout << "Engaged in combat" << std::endl;
    bool busy = true;
    bool playerTurn = rollForTrueFalse(80);     //the player character gets to go first 80% of the time 
    while(busy) {
        if(playerTurn) {
            player.displayPlayerCombatPrompt();
            std::string response = player.gatherUserInput();
            if(response == "attack" || response == "Attack") {
                if(rollForTrueFalse(90)) {
                    int tempEnemyHealth = health;
                    health = health - player.attackStat;
                    if(health <= 0) {health = 0;}
                    std::cout << "Creature takes " << player.attackStat << " damage to reduce health from " << tempEnemyHealth << " to " << health << std::endl;
                }
                else {
                    std::cout << "Attack missed!" << std::endl;
                    playerTurn = false;
                }
                playerTurn = false;
                if(health == 0) {
                    playerTurn = true;
                    busy = false;
                    std::cout << "the Enemy creature is dead" << std::endl;
                }
            }
            else if(response == "inventory" || response == "Inventory") {
                player.displayInventoryForItemUse();
                playerTurn = false;
            }
            else if (response == "flee" || response == "Flee") {
                playerTurn = true;
                busy = false;
            }
        }
        else if(!playerTurn) {
            if(rollForTrueFalse(90)) {
                std::cout << "The enemy creature attacks!" << std::endl;
                int tempHealth = player.getPlayerHealth();
                int randomDamage = getRandom(3) + attackStat;        //the creature will attack for its base attack stat plus 1,2,or3
                player.setPlayerHealth(player.getPlayerHealth() - randomDamage);
                std::cout << "Player takes " << randomDamage << " damage to reduce health from " << tempHealth << " to " << player.getPlayerHealth() << std::endl;
                playerTurn = true;
            }
            else {
                std::cout << "Enemy creature attack missed" << std::endl;
                playerTurn = true;
            }
        }
        //int random = rollForTrueFalse(100);
        //std::cout << random << std::endl;
    }
}
//MB Updated descriptions
//MB added case functionality to if
void NonCutes::examineBody(Player& player) {
    bool busy = true;
    while(busy) {
        if(!isSkinned) {
            std::cout << "You examine the body. Although truly ugly, the thick animal fur appears it may be worth something.\n[skin]\n[leave]" << std::endl;
            std::string response = player.gatherUserInput();
            if(response == "skin") {
                int slot = player.addToInventoryAndReturnSlot("animal skin");
                player.sellingPrices[slot] = skinValue;
                isSkinned = true;
                busy = false;
            }
            else if(response == "leave" || response == "Leave") { busy = false; }
        }
        else if( isSkinned) {
            std::cout << "A worthless animal carcass carelessly left to rot." << std::endl;
            busy = false;
        }
    }
}

//then a different function for deadNonCuteInteract(Player& player)
//this would make it so that we can do a flag check to see if the thing 
//is alive, then choose the appropriate interact function




