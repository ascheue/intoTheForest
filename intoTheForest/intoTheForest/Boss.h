#ifndef BOSS_H
#define BOSS_H

#include "Player.h"
#include "Creature.h"
#include <string>
#include <vector>

class Boss : public Creature {
private:
protected:
	float bossHealth;
	int bossAttackStat;
	int bossDefenseStat;
public:
	Boss();
	void engageInCombat(Player& player) override;
	/*int getBossHealth();
	void setBossHealth(int health);
	int getBossAttack();
	int getBossDefense();*/
};
#endif
#pragma once
