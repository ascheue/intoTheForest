#ifndef VENDOR_H
#define VENDOR_H

#include "Player.h"
#include <string>
#include <vector>

class Vendor {
private:
protected:
	int inventorySize;
public:
	Vendor();

	std::vector<std::string> inventoryStrings;
	std::vector<int> prices;
	void displayInventory(Player& player);
	void interact(Player& player);
	bool checkForMoney(Player& player, int slot);
};

#endif

