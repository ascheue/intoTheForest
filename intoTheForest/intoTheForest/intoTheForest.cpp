#include <iostream>
#include "Logger.h"
#include "DataModule.h"
#include "World.h"
#include "StartingTile.h"
#include "CurrentTile.h"
#include "Tile1A.h"
#include "Tile1B.h"
#include "Tile1C.h"

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

    //testing the world module
    World world;
    CurrentTile currentTile;
    StartingTile startingTile;
    Tile1A tile1a;
    Tile1B tile1b;
    Tile1C tile1c;
    logger->log("Classes loaded!");

    //bool playerIsBusy = false;
    //std::string input;  //this needs to be renamed: lines 51, 56, 61
    std::string nextMove;
    currentTile.equals(startingTile);
    //std::cout << currentTile.pathIsClear[1] << std::endl;
    while(isPlaying)
    {
        if(nextMove == "quit")
        {
            std::cout << "User has ended game." << std::endl;
            isPlaying = 0;
        }
        else
        {
            //if(playerIsBusy){
            switch (currentTile.getCurrentTileID()) 
            {
                case 0: //we are on starting tile
                    startingTile.displayText();
                    break;
                case 1: //we are on tile1a
                    //playerIsBusy = true;
                    tile1a.displayText();
                    //if(playerIsBusy) {input = world.gatherUserInput();}
                    //if(input=="leave") {playerIsBusy == false;}
                    break;
                case 2: //we are on tile1b
                    //playerIsBusy = true;
                    tile1b.displayText();
                    //if(playerIsBusy) {input = world.gatherUserInput();}
                    //if(input=="leave") {playerIsBusy == false;}
                    break;
                case 3: //we are on tile1c
                    //playerIsBusy = true;
                    tile1c.displayText();
                    //if(playerIsBusy) {input = world.gatherUserInput();}
                    //if(input=="leave") {playerIsBusy == false;}
                    break;
                default:
                    break;
            //}
            }
            //if(!playerIsBusy) {
            nextMove = world.gatherUserInput();     //literally just gets the input
            //this is the navigation block, examining what the user inputs
            if(currentTile.getCurrentTileID() == startingTile.getCurrentTileID()) {currentTile.equals(startingTile.moveToNextTile(nextMove));}
            else if(currentTile.getCurrentTileID() == tile1a.getCurrentTileID()) {currentTile.equals(tile1a.moveToNextTile(nextMove));}
            else if(currentTile.getCurrentTileID() == tile1b.getCurrentTileID()) {currentTile.equals(tile1b.moveToNextTile(nextMove));}
            else if(currentTile.getCurrentTileID() == tile1c.getCurrentTileID()) {currentTile.equals(tile1c.moveToNextTile(nextMove));}
            //}
        }
        std::cout << currentTile.getCurrentTileID() << std::endl;

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
