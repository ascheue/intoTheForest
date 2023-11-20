#include <random>
#include <chrono>
#include "Creature.h"
#include "Logger.h"

//Logger* logger2 = Logger::getInstance();

Creature::Creature() {
    health = 10;
    attackStat = 3;
    defenseStat = 3;
}

int Creature::getHealth() {
    try{
        return health;
    }
    catch(std::exception& e){
        //logger2->log("getHealth(NonCute) returned something bad: " + std::string(e.what()));
    }
}

void Creature::setHealth(int hp) {
    health = hp;
}

int Creature::getAttackStat() {
    try{
        return attackStat;
    }
    catch(std::exception& e){
        //logger2->log("getAttackStat returned something bad: " + std::string(e.what()));
    }
}

void Creature::setDefenseStat(int defense) {
    defenseStat = defense;
}

int Creature::getDefenseStat() {
    try{
        return defenseStat;
    }
    catch(std::exception& e){
        //logger2->log("getDefenseStat returned something bad: " + std::string(e.what()));
    }
}

void Creature::setAttackStat(int attack) {
    attackStat = attack;
}

void Creature::interact(Player &player) {
    //do nothing at the moment
}

int Creature::getRandom(int max) {
    std::mt19937 generator;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    generator.seed(seed);
    std::uniform_int_distribution<int> distribution(1, max);
    return distribution(generator);
}

