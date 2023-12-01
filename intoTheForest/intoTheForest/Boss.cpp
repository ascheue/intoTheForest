#include "Player.h"
#include "Logger.h"
#include "Creature.h"
#include "Boss.h"
#include <random>
#include <chrono>
#include <iostream>

using namespace std;

Boss::Boss() {
	health = 10;
	bossAttackStat = 10;
	bossDefenseStat = 5;
};

/*int Boss::getBossHealth() {
	return bossHealth;
}
void Boss::setBossHealth(int health) {
	bossHealth = health;
}*/

int getBossRandom(int max) {
	std::mt19937 generator;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	generator.seed(seed);
	std::uniform_int_distribution<int> distribution(1, max);
	return distribution(generator);
}
//Boss on player violence
std::string bossAttackSnark() {
	int bossSnark = getBossRandom(6);
	if (bossSnark == 1) {
		return "The bandit pokes you with a knife. Ouch! You take ";
	}
	else if (bossSnark == 2) {
		return "Your enemy makes fun of your haircut, dealing ";
	}
	else if (bossSnark == 3) {
		return "The bandit slashes you with his sword. You take ";
	}
	else if (bossSnark == 4) {
		return "The bandit pushes you to the ground, dealing  ";
	}
	else if (bossSnark == 5) {
		return "The bandit stuns you with his weapon, dealing ";
	}
	else {
		return "Your enemy cuts your arm with his weapon. You take ";
	}
};

//Player on boss violence 
std::string playerAttackSnark() {
	int playerSnark = getBossRandom(5);
	if (playerSnark == 1) {
		return "You attack with all of your might. You deal ";
	}
	else if (playerSnark == 2) {
		return "You should have had breakfast this morning. You hit for ";
	}
	else if (playerSnark == 3) {
		return "Violence is usually the answer, so you deal ";
	}
	else if (playerSnark == 4) {
		return "Using your trusty weapon, you hit for ";
	}
	else if (playerSnark == 5) {
		return "Your fingers feel sweaty, but you strike a blow for ";
	}
	else {
		return "Is it too late to go home? Yes. You strike out for ";
	}
};

void Boss::engageInCombat(Player& player) {
	//intro
	std::cout << "The bandit says," << std::endl;
	std::cout << "'I'm pretty impressed you've made it this far." << std::endl;
	std::cout << "But, you won't make it past me!'" << std::endl;
	std::cout << "The bandit raises his sword..." << std::endl;
	std::cout << "You are under attack!" << std::endl;

	//combat loop
	bool busy = true;
	bool playerTurn = rollForTrueFalse(70);
	while (busy) {
		if (playerTurn) {
			bool isChoosing = true;
			//player turn
			while (isChoosing) {
				player.displayPlayerCombatPrompt();
				std::string response = player.gatherUserInput();
				if (response == "attack" or "Attack") {
					isChoosing = false;
					if (rollForTrueFalse(90)) {
						int bossModifier = getBossRandom(bossDefenseStat / 2);
						if (bossModifier < player.attackStat) {
							int totalBossDamage = player.attackStat - bossModifier;
							health = health - totalBossDamage;
							if (health <= 0) {
								std::cout << playerAttackSnark() << totalBossDamage << " HP damage!" << std::endl;
								std::cout << "With a gasp, the bandit dies." << std::endl;
								playerTurn = true;
								busy = false;
							}
							else {
								std::cout << playerAttackSnark() << totalBossDamage << " HP damage!" << std::endl;
								playerTurn = false;
							}
						}
						else {
							std::cout << "He dodged the attack!" << std::endl;
							playerTurn = false;
						}
					}
					else {
						std::cout << "Your attack missed!" << std::endl;
						playerTurn = false;
					}
				}
				else if (response == "inventory" or "Inventory") {
					isChoosing = false;
					player.displayInventoryForItemUse();
				}
				else if (response == "flee" or "Flee") {
					isChoosing = false;
					std::cout << "The bandit asks, 'What are you, a coward?'" << std::endl;
					playerTurn = false;
				}
				//else {
				//	player.displayPlayerCombatPrompt();
				//	std::string response = player.gatherUserInput();
				//}
			}
		} 
		//boss turn
		else if (!playerTurn) {
			int playerModifier = getBossRandom(player.defenseStat/2);
			if (playerModifier < bossAttackStat) {
				int totalPlayerDamage = (bossAttackStat - playerModifier);
				player.setPlayerHealth(player.getPlayerHealth() - totalPlayerDamage);
				if (player.getPlayerHealth() <= 0) {
					std::cout << bossAttackSnark() << totalPlayerDamage << " HP damage!" << std::endl;
					std::cout << "You have died!" << std::endl;
					playerTurn = true;
					busy = false;
					//implement DEATH!!!
				}
				else {
					std::cout << bossAttackSnark() << totalPlayerDamage << " HP damage!" << std::endl;
					playerTurn = true;
				}
			}
			else {
				std::cout << "You dodged the attack!" << std::endl;
				playerTurn = true;
			}
		}
	}
	return;
}; 


