#pragma once
#include "Location.h"


class Railroad : public Location {
private:
	int price;

public:
	Railroad(string name, int price) {
		tileName = name;
		this->price = price;
		type = "Railroad";
	};
	int GetPrice() { return price; };
	int CalculateRent(int numRROwned);

};