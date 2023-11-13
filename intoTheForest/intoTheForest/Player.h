#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player
{
    private:
    protected:
        bool busyOnTile;
        bool currentlyEngaged;
        std::string playerInput;
        std::string nextMove;
        std::vector<std::string> inventory;
    public:
        Player();
        bool getIsBusy();
        void setIsBusy(bool busy);
        bool getIsEngaged();
        void setIsEngaged(bool engaged);
        std::string gatherUserInput();
        std::string getNextMove();
        void setNextMove(std::string move);
};

#endif