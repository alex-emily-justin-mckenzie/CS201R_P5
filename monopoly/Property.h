#pragma once
#include "Location.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

//struct PropertyRent {
//	int baseRent;
//	int house1Rent;
//	int house2Rent;
//	int house3Rent;
//	int house4Rent;
//	int hotelRent;
//
//	PropertyRent(int baseRent, int house1Rent, )
//};

class Property : public Location {

private:
	int basePrice;
	int baseRent;
	int housePrice;
	int hotelPrice;
	bool propertyOwned;

public:
	Property(string name, int price, int rent);

	//Setters + Getters

	int getBasePrice() { return basePrice; }
	// int getHotels() { return numHotels; }
	int getRent() { return baseRent; }
	//int getHouseCost() { return housePrice; }
	//string getOwnerName() { return ownerName; }
	bool getIfOwned() {return propertyOwned;}

	void setLocationName(string tName) { tileName = tName; }
	void setBasePrice(int bPrice) { basePrice = bPrice; }
	void setRent(int tRent) { baseRent = tRent; }
	// void setHouseCost(int tCost) { housePrice = tCost; }
	//void setOwner(string tOwner) {ownerName = tOwner;}


};