#ifndef ARMORFACTORY_CPP
#define ARMORFACTORY_CPP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "Player.h"
//#include "intoTheForest.cpp"

//Player player;
using namespace std;

class Head {
public:
	virtual void createHead(Player& player) = 0;
	int warriorHeadDefenseStat = 1;
	int mageHeadDefenseStat = 2;
	int rangerHeadDefenseStat = 3;
};

class Chest {
public:
	virtual void createChest(Player& player) = 0;
	int warriorCheseDefenseStat = 4;
	int mageChestDefenseStat = 5;
	int rangerChestDefenseStat = 6;
};

class Legs {
public:
	virtual void createLegs(Player& player) = 0;
	int warriorLegDefenseStat = 7;
	int mageLegDefenseStat = 8;
	int rangerLegDefenseStat = 9;
};

class Boots {
public:
	virtual void createBoots(Player& player) = 0;
	int warriorBootDefenseStat = 10;
	int mageBootDefenseStat = 11;
	int rangerBootDefenseStat = 12;
};

class Weapon {
public:
	virtual void createWeapon(Player& player) = 0;
	int warriorWeaponAttackStat= 3;
	int mageWeaponAttackStat = 1;
	int rangerWeaponAttackStat = 2;
};


class WarriorHead : public Head {
public:
	void createHead(Player &player) override {
		cout << "Metal Helmet\n";
		player.defenseStat = player.defenseStat + warriorHeadDefenseStat;
	}
};

class MageHead : public Head {
public:
	void createHead(Player &player) override {
		cout << "Wizard Hat\n";
		player.defenseStat = player.defenseStat + mageHeadDefenseStat;
	}
};

class RangerHead : public Head {
public:
	void createHead(Player &player) override {
		cout << "Pointy Cap\n";
		player.defenseStat = player.defenseStat + rangerHeadDefenseStat;
	}
};



class WarriorChest : public Chest {
public:
	void createChest(Player& player) override {
		cout << "Chainmail Armor\n";
		player.defenseStat = player.defenseStat + warriorCheseDefenseStat;
	}
};

class MageChest : public Chest {
public:
	void createChest(Player& player) override {
		cout << "Wizard's Robes\n";
		player.defenseStat = player.defenseStat + mageChestDefenseStat;
	}
};

class RangerChest : public Chest {
public:
	void createChest(Player& player) override {
		cout << "Leather Cuirass\n";
		player.defenseStat = player.defenseStat + rangerChestDefenseStat;
	}
};



class WarriorLegs : public Legs {
public:
	void createLegs(Player& player) override {
		cout << "Chainmail Leggings\n";
		player.defenseStat = player.defenseStat + warriorLegDefenseStat;
	}
};

class MageLegs : public Legs {
public:
	void createLegs(Player& player)  override {
		cout << "Wizard Pants\n";
		player.defenseStat = player.defenseStat + mageLegDefenseStat;
	}
};

class RangerLegs : public Legs {
public:
	void createLegs(Player& player)  override {
		cout << "Leather Leggings\n";
		player.defenseStat = player.defenseStat + rangerLegDefenseStat;
	}
};



class WarriorBoots : public Boots {
public:
	void createBoots(Player& player) override {
		cout << "Metal Boots\n";
		player.defenseStat = player.defenseStat + warriorBootDefenseStat;
	}
};

class MageBoots : public Boots {
public:
	void createBoots(Player& player)  override {
		cout << "Wizard Boots\n";
		player.defenseStat = player.defenseStat + mageBootDefenseStat;
	}
};

class RangerBoots : public Boots {
public:
	void createBoots(Player& player)  override {
		cout << "Leather Boots\n";
		player.defenseStat = player.defenseStat + rangerBootDefenseStat;
	}
};



class WarriorWeapon : public Weapon {
public:
	void createWeapon(Player& player) override {
		cout << "Metal Sword\n";
		player.attackStat = player.attackStat + warriorWeaponAttackStat;
	}
};

class MageWeapon : public Weapon {
public:
	void createWeapon(Player& player)  override {
		cout << "Magical Staff\n";
		player.attackStat = player.attackStat + mageWeaponAttackStat;
	}
};

class RangerWeapon : public Weapon {
public:
	void createWeapon(Player& player)  override {
		cout << "Hunter's Bow\n";
		player.attackStat = player.attackStat + rangerWeaponAttackStat;
	}
};

class Armor {
public:
	virtual Head* createHead(Player &player) const = 0;
	virtual Chest* createChest(Player& player) const = 0;
	virtual Legs* createLegs(Player& player) const = 0;
	virtual Boots* createBoots(Player& player) const = 0;
	virtual Weapon* createWeapon(Player& player) const = 0;
};

class WarriorArmor : public Armor {
public:
	Head* createHead(Player &player) const override {
		return new WarriorHead();
	};
	Chest* createChest(Player& player) const override {
		return new WarriorChest();
	};
	Legs* createLegs(Player& player) const override {
		return new WarriorLegs();
	};
	Boots* createBoots(Player& player) const override {
		return new WarriorBoots();
	};
	Weapon* createWeapon(Player& player) const override {
		return new WarriorWeapon();
	};
};
class MageArmor : public Armor {
public:
	Head* createHead(Player &player) const override {
		return new MageHead();
	};
	Chest* createChest(Player& player) const override {
		return new MageChest();
	};
	Legs* createLegs(Player& player) const override {
		return new MageLegs();
	};
	Boots* createBoots(Player& player) const override {
		return new MageBoots();
	};
	Weapon* createWeapon(Player& player) const override {
		return new MageWeapon();
	};
};

class RangerArmor : public Armor {
public:
	Head* createHead(Player &player) const override {
		return new RangerHead();
	};
	Chest* createChest(Player& player) const override {
		return new RangerChest();
	};
	Legs* createLegs(Player& player) const override {
		return new RangerLegs();
	};
	Boots* createBoots(Player& player) const override {
		return new RangerBoots();
	};
	Weapon* createWeapon(Player& player) const override {
		return new RangerWeapon();
	};
};

#endif
/*int main() {
	std::string CharacterClass;
	std::cin >> CharacterClass;
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
	};
	if (factory) {
		Head* head = factory->createHead();
		Chest* chest = factory->createChest();
		Legs* legs = factory->createLegs();
		Boots* boots = factory->createBoots();
		Weapon* weapon = factory->createWeapon();

		head->createHead();
		chest->createChest();
		legs->createLegs();
		boots->createBoots();
		weapon->createWeapon();

		delete head;
		delete chest;
		delete legs;
		delete boots;
		delete weapon;
		delete factory;
	}
	return 0;
};*/