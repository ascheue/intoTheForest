#include <iostream>
//#include "Logger.h"
#include "DataModule.h"
#include "World.h"
#include "StartingTile.h"
#include "CurrentTile.h"
#include "Tile1A.h"
#include "Tile1B.h"
#include "Tile1C.h"

int main()
{
    bool isPlaying = 1;
    //testing the Logger
    //Logger* logger = Logger::getInstance();
    //logger->log("This is a test to see if we can write to a file0");

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

    std::string nextMove;
    currentTile.equals(startingTile);

    while(isPlaying)
    {

        nextMove = world.gatherUserInput();     //literally just gets the input
        if(nextMove == "quit"){
            std::cout << "User has ended game." << std::endl;
            isPlaying = 0;
        }
        else{
            switch (currentTile.getCurrentTileID()) {
                case 0:
                    if(nextMove == currentTile.listOfNavigations[0]) {currentTile.equals(tile1a);}
                    else if(nextMove == currentTile.listOfNavigations[1]) {currentTile.equals(tile1b);}
                    else if(nextMove == currentTile.listOfNavigations[2]) {currentTile.equals(tile1c);}
                    else std::cout << "selection not found" << std::endl;
                    break;
                case 1:
                    if(nextMove == currentTile.listOfNavigations[0]) {currentTile.equals(startingTile);}
                    else std::cout << "selection not found1" << std::endl;
                    break;
                case 2:
                    if(nextMove == currentTile.listOfNavigations[0]) {currentTile.equals(startingTile);}
                    else std::cout << "selection not found2" << std::endl;
                    break;
                case 3:
                    if(nextMove == currentTile.listOfNavigations[0]) {currentTile.equals(startingTile);}
                    else std::cout << "selection not found3" << std::endl;
                    break;
                default:
                    break;
            }
            switch (currentTile.getCurrentTileID()) {
                case 0:
                    startingTile.displayText();
                    break;
                case 1:
                    tile1a.displayText();
                    break;
                case 2:
                    tile1b.displayText();
                    break;
                case 3:
                    tile1c.displayText();
                    break;
                default:
                    break;
            }
        }
        std::cout << currentTile.tileID << std::endl;

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
