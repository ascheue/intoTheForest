#include "Vendor.h"
#include "World.h"
#include "Player.h"
#include <iostream>

Vendor::Vendor() {
    inventoryStrings.push_back("some Bullshit");
    prices.push_back(5);
    inventoryStrings.push_back("some other Bullshit");
    prices.push_back(10);
    inventoryStrings.push_back("pickaxe");
    prices.push_back(25);
    inventoryStrings.push_back("");
    prices.push_back(0);
    inventoryStrings.push_back("");
    prices.push_back(0);
}

void Vendor::interact(Player& player) {
    bool busy = true;
    std::cout << "in interact loop" << std::endl;
    while(busy){
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
        std::string response = player.gatherUserInput();
        /*
        for(int i=0;i<sizeof(inventoryStrings);i++) {
            if(checkForMoney(player, i)) {
                player.addToInventory(response);
                inventoryStrings[i] = "";
            }
            else{
                std::cout << "cant afford bitch!" << std::endl;
            }
        }
        */
        if(response == inventoryStrings[0]) {
            if(checkForMoney(player, 0)) {
                player.addToInventory(response);
                inventoryStrings[0] = "";
            }
            else{
                std::cout << "cant afford bitch!" << std::endl;
            }
        }
        else if(response == inventoryStrings[1]) {
            player.addToInventory(response);
            inventoryStrings[1] = "";
        }
        else if(response == inventoryStrings[2]) {
            player.addToInventory(response);
            inventoryStrings[2] = "";

        }
        else if(response == inventoryStrings[3]) {
            player.addToInventory(response);
            inventoryStrings[3] = "";
        }
        else if(response == inventoryStrings[4]) {
            player.addToInventory(response);
            inventoryStrings[4] = "";
        }
        else if(response == "leave") {busy = false;}
        else {std::cout << "Selection not found2" << std::endl;}
    }
}

bool Vendor::checkForMoney(Player& player, int slot) {
    if(player.getWallet() >= prices[slot]){
        return true;
    }
    return false;
}