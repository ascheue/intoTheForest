#ifndef VENDOR_H
#define VENDOR_H

#include "Player.h"
#include <string>
#include <vector>

class Vendor {
private:
protected:
public:
	Vendor();

	std::vector<std::string> inventoryStrings;
	std::vector<int> prices;
	void interact(Player& player);
	bool checkForMoney(Player& player, int slot);
};

#endif

