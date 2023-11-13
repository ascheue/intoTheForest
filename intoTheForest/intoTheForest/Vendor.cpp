#include "Vendor.h"
#include "World.h"
#include "Player.h"
#include <iostream>

Vendor::Vendor() {
    invnetoryStrings.push_back("some Bullshit");
    invnetoryStrings.push_back("some other Bullshit");
    invnetoryStrings.push_back("pickaxe");
    invnetoryStrings.push_back("");
    invnetoryStrings.push_back("");
}

void Vendor::interact() {
    World world;
    Player player;
    bool busy = true;
    std::cout << "in interact loop" << std::endl;
    while(busy){
        Player player;
        std::string response;
        std::cout << "What would you like to purchase?" << std::endl;
        if(invnetoryStrings[0] == "") {std::cout << "" << std::endl;}
        else {std::cout << "some Bullshit.............$5" << std::endl;}
        if(invnetoryStrings[1] == "") {std::cout << "" << std::endl;}
        else {std::cout << "some other Bullshit.......$10" << std::endl;} 
        if(invnetoryStrings[2] == "") {std::cout << "" << std::endl;}
        else {std::cout << "pickaxe...................$25" << std::endl;}
        if(invnetoryStrings[3] == "") {std::cout << "" << std::endl;}
        else {std::cout << "" << std::endl;}
        if(invnetoryStrings[4] == "") {std::cout << "" << std::endl;}
        else {std::cout << "" << std::endl;}
        std::cout << ">> ";
        std::getline(std::cin, response);
        if(response == invnetoryStrings[0]) {invnetoryStrings[0] = "";}
        else if(response == invnetoryStrings[1]) {invnetoryStrings[1] = "";}
        else if(response == invnetoryStrings[2]) {invnetoryStrings[2] = "";}
        else if(response == invnetoryStrings[3]) {invnetoryStrings[3] = "";}
        else if(response == invnetoryStrings[4]) {invnetoryStrings[4] = "";}
        else if(response == "leave") {busy = false;}
        else {std::cout << "Selection not found2" << std::endl;}
    }
}