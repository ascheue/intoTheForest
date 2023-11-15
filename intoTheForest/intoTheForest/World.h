#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <vector>
#include <map>



class World {
private:

protected:
//public:
    std::string tileName;
    int tileID;
    int numAdjacents;
    int numNavigations;
    std::vector<std::string> listOfNavigations;
    std::vector<bool> pathIsClear;
    std::vector<World> listOfAdjacents;
    bool isCurrentLevel;
    bool hasBeenVisited;
    std::string welcomeMessage;
    std::string revisitMessage;
    
    std::string nextAction;
    //std::map<std::string, World> actionsToAdvanceTile;
public:
    std::string navMessage;
    World();

    void displayText();
    virtual std::string gatherUserInput();

    virtual World getCurrentWorld();
    virtual std::string getCurrentTileName();
    virtual int getCurrentTileID();
    virtual int getNumAdjacents();
    virtual int getNumNavigations();
    virtual std::string getNavigation(int i);
    virtual std::string getNextMove();
    virtual void setNextMove(std::string move);
    //virtual World getListOfAdjacents();
    
    virtual bool isPathClear(int i);
    virtual void clearPathForward(int i);
    virtual bool tileIsAdjacent(World tile);
    void equals(const World& otherWorld);
    virtual World moveToNextTile(std::string tileSelection);
    virtual void setNextAction(std::string action);
    virtual std::string getNextAction();

};

#endif