#pragma once
#include "Location.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

struct PropertyRent {
	int baseRent;
	int house1Rent;
	int house2Rent;
	int house3Rent;
	int house4Rent;
	int hotelRent;

	PropertyRent(int baseRent, int house1Rent, int house2Rent, int house3Rent, int house4Rent, int hotelRent);
	PropertyRent() {
		baseRent = 0;
		house1Rent = 0;
		house2Rent = 0;
		house3Rent = 0;
		house4Rent = 0;
		hotelRent = 0;
	}
};

class Property : public Location {

private:
	int basePrice;
	int housePrice;
	int mortgage;
	bool propertyOwned;
	PropertyRent rentLevels;
	int currentRent;
	string group;
	string tileOwner;


	// Don't want the tiles to have information about the players like number of houses they own or even who owns the property
	// The player/the bank should keep track of that info

public:
	Property(string name, int price, int housePrice, PropertyRent rentLevels, int mortgage, string group);

	//Setters + Getters

	int getBasePrice() { return basePrice; }
	bool getIfOwned() {return propertyOwned;}

	void updateRent(); // update currentRent if owner adds real estate
	// Don't really need setters since tiles don't change throughout the game. Only need constructor
	void setLocationName(string tName) { tileName = tName; }
	void setBasePrice(int bPrice) { basePrice = bPrice; }
	string getOwnerName() { return tileOwner; };
	int getCurrentRent() { return currentRent; };

};