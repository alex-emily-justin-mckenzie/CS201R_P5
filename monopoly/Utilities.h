#pragma once
#include "Location.h"

class Utilities : public Location {
private: 
	int price;

public:
	Utilities(string name, int price) {
		tileName = name;
		this->price = price;
		type = "Utilities";
	};
	int GetPrice() { return price; };
	int CalculateRent(int diceTotal, int numUtilOwned);
};