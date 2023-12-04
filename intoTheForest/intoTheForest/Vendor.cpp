#include "Vendor.h"
#include "World.h"
//#include "Player.h"
#include <iostream>

Vendor::Vendor() {
    inventoryStrings.push_back("magic scroll");
    prices.push_back(100);
    inventoryStrings.push_back("key to the kingdom");
    prices.push_back(750);
    inventoryStrings.push_back("pickaxe");
    prices.push_back(25);
    inventoryStrings.push_back("'Not Fake' Crown");
    prices.push_back(2500);
    inventoryStrings.push_back("really big potato");
    prices.push_back(50);

    inventorySize = 5;
}

void Vendor::displayInventory() {
    std::cout << "Vendor Inventory:" << std::endl;
    for(int i=0; i<inventorySize; i++){
        if(inventoryStrings[i] == "") {std::cout << "" << prices[i] << std::endl;}
        else {std::cout << inventoryStrings[i] << ": $" << prices[i] << std::endl;}
    }
}

void Vendor::interact(Player& player) {
    bool isSelecting = true;
    std::cout << "'Good day, friend!' the old man says warmly." << std::endl;
    std::cout << "'I haven't seen many travelers since the bandits came through." << std::endl;
    std::cout << "Are you by chance in need of any supplies?'" << std::endl;
    while(isSelecting) {
        std::cout << "What would you like to do?\n[buy]\n[sell]" << std::endl;
        std::string input = player.gatherUserInput();
        if(input == "Buy" || input == "buy") {
            sellToPlayer(player);
            isSelecting = false;
        }
        else if(input == "Sell" || input == "sell") {
            buyFromPlayer(player);
            isSelecting = false;
        }
        else {
            std::cout << "The old man looks at you with confusion." << std::endl;
        }
    }
}

bool Vendor::checkForMoney(Player& player, int slot) {
    if(player.getWallet() >= prices[slot]){
        return true;
    }
    return false;
}

void Vendor::addToInventory(std::string item) {
    for(int i=0;i<inventorySize;i++){
        if(inventoryStrings[i] == ""){
            inventoryStrings[i] = item;

            return;
        }
    }
    inventoryStrings.push_back(item);
}

int Vendor::addToInventoryAndReturnSlot(std::string item) {
    for(int i=0;i<inventorySize;i++){
        if(inventoryStrings[i] == ""){
            inventoryStrings[i] = item;

            return i;
        }
    }
    inventoryStrings.push_back(item);
}

void Vendor::removeFromInventory(std::string item) {
    for(int i=0; i<inventorySize; i++){ 
        if(inventoryStrings[i] == item){
            inventoryStrings[i] = "";
            return;
        }
        std::cout <<"removeFromInventory could not find " << item << " in inventory!!1" << std::endl;

    }
}

//Buy
void Vendor::sellToPlayer(Player& player) {
    bool busy = true;
    bool itemFound = false;
    while(busy){
        displayInventory();
        player.displayInventory();
        std::cout << "[leave]" << std::endl;
        std::string response = player.gatherUserInput();

        for(int i=0; i<inventorySize; i++){
            if(response == inventoryStrings[i]) {
                itemFound = true;
                if(checkForMoney(player, i)) {
                    int slot = player.addToInventoryAndReturnSlot(response);
                    player.sellingPrices[slot] = prices[i];
                    inventoryStrings[i] = "";
                    player.addToWallet(prices[i]*-1);
                    prices[i] = 0;
                }
                else{
                    std::cout << "Alas, your wallet shows you cannot afford this." << std::endl;
                }
            }
        }
        if(response == "leave") {busy = false;}
        else if(!itemFound) {std::cout << "Selection Not Found" << std::endl;}
        itemFound = false;
    }
}

//Sell
void Vendor::buyFromPlayer(Player& player) {
    bool busy = true;
    while(busy){
        std::cout << "What would you like to sell?" << std::endl;
        displayInventory();
        player.displayInventory();
        std::cout << "[leave]" << std::endl;
        std::string response = player.gatherUserInput();

        for(int i=0; i<player.getInventorySize(); i++){
            if(response == player.inventory[i]) {
                int slot = addToInventoryAndReturnSlot(response);
                //int slot1 = player.sellItemAndReturnSlot(response);
                player.sellItem(response);
                prices[slot] = player.sellingPrices[i];
                player.sellingPrices[i] = 0;
            }
        }
        if(response == "leave") {busy = false;}
    }
}