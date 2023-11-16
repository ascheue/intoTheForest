#ifndef VENDOR_H
#define VENDOR_H

#include <string>
#include <vector>

class Vendor {
private:
protected:
public:
	Vendor();

	std::vector<std::string> inventoryStrings;
	void interact();
};

#endif

