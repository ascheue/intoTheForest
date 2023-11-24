#include "NonCutes.h"
#include "Logger.h"
#include "Player.h"
#include <iostream>



NonCutes::NonCutes() {
    health = 10;
    attackStat = 3;
    defenseStat = 3;
}

void NonCutes::interact(Player &player) {
    std::cout << "The creature Turns hostile, what will you do?\n[flee]\n[attack]" << std::endl;
    std::string response = player.gatherUserInput();
    if(response == "attack") {
        engageInCombat(player);
    }
    else if(response == "flee") {std::cout << "You successfully escape the creature" << std::endl;}
    else {std::cout << "you wanna do what?" << std::endl;}
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
            if(response == "attack") {
                if(rollForTrueFalse(90)) {health = health - player.attackStat;}
                else {std::cout << "Attack missed!" << std::endl;}
                std::cout << "Enemy health: " << health << std::endl;
            }
            else if(response == "inventory") {
                player.displayInventoryForItemUse();
                //playerTurn = false;
            }
        }
        else if(!playerTurn) {

        }
        //int random = rollForTrueFalse(100);
        //std::cout << random << std::endl;
    }
}

//then a different function for deadNonCuteInteract(Player& player)
//this would make it so that we can do a flag check to see if the thing 
//is alive, then choose the appropriate interact function




