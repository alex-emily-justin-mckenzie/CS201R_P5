#pragma once
// #include "basePlayerHeader.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

class Location {

protected:
	string tileName;
	string type;
	// string tileLocation;
	//int numLocation;
	//int basePrice;
	//int numHotels;
	//int baseRent;
	//int houseCost;
	//bool propertyOwned;
	//string ownerName;

public:
	Location();
	Location(string tileName, string type);
	string getTileName() { return tileName; }
	string getType() { return type; }

};
