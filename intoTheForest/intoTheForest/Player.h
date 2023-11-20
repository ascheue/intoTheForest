#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player
{
    private:
    protected:
        float playerHealth;
        std::string playerClass;
        bool busyOnTile;
        bool currentlyEngaged;
        int wallet;
        int inventorySize;
        std::string playerInput;
        std::string nextMove;
        
    public:
        std::vector<std::string> inventory; //to make this protected will take modifiying vendor class
             //TODO: make these protected
        int defenseStat;
        int attackStat;
        Player();
        void characterSelectionPrompt();
        int getPlayerHealth();
        void setPlayerHealth(int health);
        std::string getPlayerClass();
        void setPlayerClass(std::string newClass);
        bool getIsBusy();
        void setIsBusy(bool busy);
        int getWallet();
        void setWallet(int money);
        void addToWallet(int addition);
        bool getIsEngaged();
        void setIsEngaged(bool engaged);
        std::string gatherUserInput();
        std::string getNextMove();
        void setNextMove(std::string move);
        void addToInventory(std::string item);
        bool containsInInventory(std::string item);
};

#endif