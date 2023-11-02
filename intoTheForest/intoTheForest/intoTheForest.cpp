// intoTheForest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include "Logger.h"
//#include "DataModule.h"
#include "World.h"
#include "StartingTile.h"
#include "CurrentTile.h"

int main()
{
    //testing the Logger
    //Logger* logger = Logger::getInstance();
    //logger->log("This is a test to see if we can write to a file0");
 

    //testing the DataModule
    //DataModule dm;
    //dm.add("FirstKey", 1);
    //dm.add("2ndKey",   2);
    //dm.printAll();


    //testing the world module
    World world;
    CurrentTile currentTile;
    StartingTile startingTile; 
    currentTile.equals(startingTile);
    std::cout << "active value: " << currentTile.getCurrentTile() << std::endl;
    if (currentTile.tileIsAdjacent(Tile1A)) {
        std::cout << "Tile is adjacent!" << std::endl;
        std::cout << currentTile.listOfAdjacents[1] << std::endl;
    }
    else{
        std::cout << "Tile is NOT adjacent!" << std:: endl;
    }
    //TODO: create a Tile1A class to test moving to adjacent tiles.
    
    



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
