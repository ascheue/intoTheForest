#include "Vendor.h"
#include "World.h"
#include "Player.h"
#include <iostream>

Vendor::Vendor() {
    inventoryStrings.push_back("some Bullshit");
    inventoryStrings.push_back("some other Bullshit");
    inventoryStrings.push_back("pickaxe");
    inventoryStrings.push_back("");
    inventoryStrings.push_back("");
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
        if(inventoryStrings[0] == "") {std::cout << "" << std::endl;}
        else {std::cout << "some Bullshit.............$5" << std::endl;}
        if(inventoryStrings[1] == "") {std::cout << "" << std::endl;}
        else {std::cout << "some other Bullshit.......$10" << std::endl;} 
        if(inventoryStrings[2] == "") {std::cout << "" << std::endl;}
        else {std::cout << "pickaxe...................$25" << std::endl;}
        if(inventoryStrings[3] == "") {std::cout << "" << std::endl;}
        else {std::cout << "" << std::endl;}
        if(inventoryStrings[4] == "") {std::cout << "" << std::endl;}
        else {std::cout << "" << std::endl;}
        std::cout << ">> ";
        std::getline(std::cin, response);
        if(response == inventoryStrings[0]) {inventoryStrings[0] = "";}
        else if(response == inventoryStrings[1]) {inventoryStrings[1] = "";}
        else if(response == inventoryStrings[2]) {inventoryStrings[2] = "";}
        else if(response == inventoryStrings[3]) {inventoryStrings[3] = "";}
        else if(response == inventoryStrings[4]) {inventoryStrings[4] = "";}
        else if(response == "leave") {busy = false;}
        else {std::cout << "Selection not found2" << std::endl;}
    }
}