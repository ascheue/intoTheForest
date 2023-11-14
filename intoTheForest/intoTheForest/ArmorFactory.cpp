#ifndef ARMORFACTORY_CPP
#define ARMORFACTORY_CPP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "Player.h"

//Player unique_player;
using namespace std;

class Head {
public:
	virtual void createHead() = 0;
};

class WarriorHead : public Head {
public:
	void createHead() override {
		cout << "Metal Helmet\n";
		//player.defenceStat = player.defenceStat + 3;
	}
};

class MageHead : public Head {
public:
	void createHead() override {
		cout << "Wizard Hat\n";
		//player.defenceStat = player.defenceStat + 1;
	}
};

class RangerHead : public Head {
public:
	void createHead() override {
		cout << "Pointy Cap\n";
		//player.defenceStat = player.defenceStat + 2;
	}
};

class Chest {
public:
	virtual void createChest() = 0;
};

class WarriorChest : public Chest {
public:
	void createChest() override {
		cout << "Chainmail Armor\n";
	}
};

class MageChest : public Chest {
public:
	void createChest() override {
		cout << "Wizard's Robes\n";
	}
};

class RangerChest : public Chest {
public:
	void createChest() override {
		cout << "Leather Cuirass\n";
	}
};

class Legs {
public:
	virtual void createLegs() = 0;
};

class WarriorLegs : public Legs {
public:
	void createLegs() override {
		cout << "Chainmail Leggings\n";
	}
};

class MageLegs : public Legs {
public:
	void createLegs()  override {
		cout << "Wizard Pants\n";
	}
};

class RangerLegs : public Legs {
public:
	void createLegs()  override {
		cout << "Leather Leggings\n";
	}
};

class Boots {
public:
	virtual void createBoots() = 0;
};

class WarriorBoots : public Boots {
public:
	void createBoots() override {
		cout << "Metal Boots\n";
	}
};

class MageBoots : public Boots {
public:
	void createBoots()  override {
		cout << "Wizard Boots\n";
	}
};

class RangerBoots : public Boots {
public:
	void createBoots()  override {
		cout << "Leather Boots\n";
	}
};

class Weapon {
public:
	virtual void createWeapon() = 0;
};

class WarriorWeapon : public Weapon {
public:
	void createWeapon() override {
		cout << "Metal Sword\n";
	}
};

class MageWeapon : public Weapon {
public:
	void createWeapon()  override {
		cout << "Magical Staff\n";
	}
};

class RangerWeapon : public Weapon {
public:
	void createWeapon()  override {
		cout << "Hunter's Bow\n";
	}
};

class Armor {
public:
	virtual Head* createHead() const = 0;
	virtual Chest* createChest() const = 0;
	virtual Legs* createLegs() const = 0;
	virtual Boots* createBoots() const = 0;
	virtual Weapon* createWeapon() const = 0;
};

class WarriorArmor : public Armor {
public:
	Head* createHead() const override {
		return new WarriorHead();
	};
	Chest* createChest() const override {
		return new WarriorChest();
	};
	Legs* createLegs() const override {
		return new WarriorLegs();
	};
	Boots* createBoots() const override {
		return new WarriorBoots();
	};
	Weapon* createWeapon() const override {
		return new WarriorWeapon();
	};
};
class MageArmor : public Armor {
public:
	Head* createHead() const override {
		return new MageHead();
	};
	Chest* createChest() const override {
		return new MageChest();
	};
	Legs* createLegs() const override {
		return new MageLegs();
	};
	Boots* createBoots() const override {
		return new MageBoots();
	};
	Weapon* createWeapon() const override {
		return new MageWeapon();
	};
};

class RangerArmor : public Armor {
public:
	Head* createHead() const override {
		return new RangerHead();
	};
	Chest* createChest() const override {
		return new RangerChest();
	};
	Legs* createLegs() const override {
		return new RangerLegs();
	};
	Boots* createBoots() const override {
		return new RangerBoots();
	};
	Weapon* createWeapon() const override {
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