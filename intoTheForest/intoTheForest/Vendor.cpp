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

    inventorySize = 5;
}

void Vendor::displayInventory(Player& player) {
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
    std::cout << "Player Wallet: " << player.getWallet() << std::endl;
    std::cout << "[leave]" << std::endl;
}

void Vendor::interact(Player& player) {
    bool busy = true;
    bool itemFound;
    std::cout << "in interact loop" << std::endl;
    while(busy){
        displayInventory(player);
        std::string response = player.gatherUserInput();

        for(int i=0; i<inventorySize; i++){
            if(response == inventoryStrings[i]) {
                itemFound = true;
                if(checkForMoney(player, i)) {
                    player.addToInventory(response);
                    inventoryStrings[i] = "";
                    player.addToWallet(prices[i]*-1);
                }
                else{
                    std::cout << "cant afford bitch!" << std::endl;
                }
            }
        }
        if(response == "leave") {busy = false;}
        if(!itemFound) {std::cout << "Selection Not Found" << std::endl;}
        itemFound = false;
    }
}

bool Vendor::checkForMoney(Player& player, int slot) {
    if(player.getWallet() >= prices[slot]){
        return true;
    }
    return false;
}