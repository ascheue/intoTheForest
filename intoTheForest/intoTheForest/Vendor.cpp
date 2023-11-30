#include "Vendor.h"
#include "World.h"
//#include "Player.h"
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

void Vendor::displayInventory() {
    std::cout << "Vendor Inventory:" << std::endl;
    for(int i=0; i<inventorySize; i++){
        if(inventoryStrings[i] == "") {std::cout << "" << prices[i] << std::endl;}
        else {std::cout << inventoryStrings[i] << ": $" << prices[i] << std::endl;}
    }
    /*if(inventoryStrings[0] == "") {std::cout << "" << std::endl;}
    else {std::cout << "some Bullshit.............$5" << std::endl;}
    if(inventoryStrings[1] == "") {std::cout << "" << std::endl;}
    else {std::cout << "some other Bullshit.......$10" << std::endl;}
    if(inventoryStrings[2] == "") {std::cout << "" << std::endl;}
    else {std::cout << "pickaxe...................$25" << std::endl;}
    if(inventoryStrings[3] == "") {std::cout << "" << std::endl;}
    else {std::cout << "" << std::endl;}
    if(inventoryStrings[4] == "") {std::cout << "" << std::endl;}
    else {std::cout << "" << std::endl;}*/
}

void Vendor::interact(Player& player) {
    bool isSelecting = true;
    while(isSelecting) {
        std::cout << "What would you like to do?\n[Buy]\n[Sell]" << std::endl;
        std::string input = player.gatherUserInput();
        if(input == "Buy"){
            sellToPlayer(player);
            isSelecting = false;
        }
        else if(input == "Sell"){
            buyFromPlayer(player);
            isSelecting = false;
        }
        else {
            std::cout << "You wanna what??" << std::endl;
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

                    //player.sellingPrices[i] = 

                }
                else{
                    std::cout << "cant afford bitch!" << std::endl;
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