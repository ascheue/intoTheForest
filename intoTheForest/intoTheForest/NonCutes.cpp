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
    std::cout << "The creature Turns hostile, what will you do?" << std::endl;
    std::cout << "[flee]\n[attack]" << std::endl;
    std::string response = player.gatherUserInput();
    bool inCombat = false;
    if(response == "attack") {inCombat = true;}
    while(inCombat){                        //I say we get rid of this loop, then write a separate function for nonCutes.engageInCombat(Player& player)
        int rand = getRandom(10);
        std::cout << "Random number: " << rand << std::endl;

        if(response == "flee") {inCombat = false;}
        inCombat = false;
    }
}




