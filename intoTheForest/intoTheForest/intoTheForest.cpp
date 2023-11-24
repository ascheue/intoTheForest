#include <iostream>
#include "Logger.h"
#include "DataModule.h"
#include "World.h"
#include "StartingTile.h"
#include "CurrentTile.h"
#include "Tile1A.h"
#include "Tile1B.h"
#include "Tile1C.h"
#include "Tile2C.h"
#include "Player.h"
#include "Vendor.h"
#include "NonCutes.h"
#include "ArmorFactory.cpp"


int main()
{
    Logger* logger = Logger::getInstance();
    logger->log("New Run---------------------------------------------------------------------------------------------------------------------------------------------------------------");
    bool isPlaying = 1;

    //testing the DataModule
    DataModule dm;
    //dm.add("FirstKey", 1);
    //dm.add("2ndKey",   2);
    //dm.printAll();

    World world;
    CurrentTile currentTile;
    StartingTile startingTile;
    Tile1A tile1a;
    Tile1B tile1b;
    Tile1C tile1c;
    Tile2C tile2c;
    Player player;
    Vendor vendor;
    NonCutes nonCute;
    logger->log("Classes loaded!");
    currentTile.equals(tile1b);
    //------------------------------------------------------------------------------------
    player.characterSelectionPrompt();
    std::string CharacterClass = "Mage";
	//std::getline(std::cin, CharacterClass);
	player.setPlayerClass(CharacterClass);
    Armor* factory = nullptr;

	if (CharacterClass == "Warrior") {
		factory = new WarriorArmor();
	}
	else if (CharacterClass == "Mage") {
		factory = new MageArmor();
	}
	else if (CharacterClass == "Ranger") {
		factory = new RangerArmor();
	}
	else {
		cout << "You always dreamed of being a " << CharacterClass << " but alas, your parents would never allow it.\n";
		return 1;
	}
	if (factory) {
		Head* head = factory->createHead(player);
		Chest* chest = factory->createChest(player);
		Legs* legs = factory->createLegs(player);
		Boots* boots = factory->createBoots(player);
		Weapon* weapon = factory->createWeapon(player);

		head->createHead(player);
		chest->createChest(player);
		legs->createLegs(player);
		boots->createBoots(player);
		weapon->createWeapon(player);

	    delete head;
		delete chest;
		delete legs;
		delete boots;
		delete weapon;
		delete factory;
    }
    std::cout << "Defense:" << std::endl;
    std::cout << player.defenseStat << std::endl;
    std::cout << "Attack:" << std::endl;
    std::cout << player.attackStat << std::endl;
    //player.displayInventory();
    //------------------------------------------------------------------------------------
    while(isPlaying)
    {
        if(world.getNextMove() == "quit" || player.getNextMove() == "quit")//next move
        {
            std::cout << "User has ended game." << std::endl;
            isPlaying = 0;
        }
        else
        {
            if(player.getIsBusy())      //quit condition doesnt work in this loop
            {
                switch (currentTile.getCurrentTileID())
                {
                    case 0: //we are on starting tile
                        startingTile.displayText();
                        player.setNextMove(player.gatherUserInput());
                        break;
                    case 1: //we are on tile1a
                        tile1a.displayText();
                        player.setNextMove(player.gatherUserInput());
                        if(player.getNextMove() == "approach") {vendor.interact(player);}
                        break;
                    case 2: //we are on tile1b
                        tile1b.displayText();
                        player.setNextMove(player.gatherUserInput());
                        if (player.getNextMove() == "interact") { nonCute.interact(player); }
                        break;
                    case 3: //we are on tile1c
                        tile1c.displayText();
                        if (player.containsInInventory("pickaxe")) { tile1c.clearPathForward(1); }  //pickaxe check
                        player.setNextMove(player.gatherUserInput());
                        break;
                    case 4: //we are on tile2c
                        tile2c.displayText();
                        player.setNextMove(player.gatherUserInput());
                        break;
                    default:
                        break;
                }
            }
            if(!player.getIsBusy()) 
            {
                //int temp = currentTile.getCurrentTileID();
                std::cout << "Where would you like to go?" <<  std::endl;
                std::cout << currentTile.navMessage <<  std::endl;
                world.setNextAction(world.gatherUserInput());     //literally just gets the input, next move
                //this is the navigation block, examining what the user inputs
                if(currentTile.getCurrentTileID() == startingTile.getCurrentTileID()) {
                    currentTile.equals(startingTile.moveToNextTile(world.getNextMove()));
                    player.setIsBusy(true);
                }
                else if(currentTile.getCurrentTileID() == tile1a.getCurrentTileID()) {
                    currentTile.equals(tile1a.moveToNextTile(world.getNextMove()));
                    player.setIsBusy(true);
                }
                else if(currentTile.getCurrentTileID() == tile1b.getCurrentTileID()) {
                    currentTile.equals(tile1b.moveToNextTile(world.getNextMove()));
                    player.setIsBusy(true);
                }
                else if(currentTile.getCurrentTileID() == tile1c.getCurrentTileID()) {
                    currentTile.equals(tile1c.moveToNextTile(world.getNextMove()));
                    player.setIsBusy(true);
                }
                else if(currentTile.getCurrentTileID() == tile2c.getCurrentTileID()) {
                    currentTile.equals(tile2c.moveToNextTile(world.getNextMove()));
                    player.setIsBusy(true);
                }
                //if(temp != currentTile.getCurrentTileID()) {player.setIsBusy(true);}
            }
        }
        //std::cout << currentTile.getCurrentTileID() << std::endl; //troubleshooting

    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
