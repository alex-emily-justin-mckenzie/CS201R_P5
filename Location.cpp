#include "Location.h"
Location::Location() {
	name = "";
	type = "";
}

Location::~Location() {

}

Location::Location(string locName, string locType) {
	name = locName;
	type = locType;
}
string Location::getName() const { return name; }
string Location::getType() const { return type; }
Property::Property() {
	price = 0;
	owner = 0;
}
Property::Property(int buyPrice, int ownedBy) {
	price = buyPrice;
	owner = ownedBy;
}

Property::~Property() {

}

Corner::Corner(string name) {
	this->name = name;
}

ChanceCC::ChanceCC(string name) {
	this->name = name;
}

Tax::Tax(string name) {
	this->name = name;
}

int Property::getPrice() const { return price; }
int Property::getOwner() const { return owner; }
void Property::setOwner(int playerNum) { owner = playerNum; }

Regular::Regular(string name, int Rent, int H1Rent, int H2Rent, int H3Rent, int H4Rent, int H5Rent, int HPrice, string Color) {
	rent = Rent;
	house1Rent = H1Rent;
	house2Rent = H2Rent;
	house3Rent = H3Rent;
	house4Rent = H4Rent;
	hotelRent = H5Rent;
	housePrice = HPrice;
	colorGroup = Color;
	type = "Regular";
	this->name = name;
}
int Regular::getRent() const { return rent; }
int Regular::getH1Rent() const { return house1Rent; }
int Regular::getH2Rent() const { return house2Rent; }
int Regular::getH3Rent() const { return house3Rent; }
int Regular::getH4Rent() const { return house4Rent; }
int Regular::getH5Rent() const { return hotelRent; }
int Regular::getHPrice() const { return housePrice; }
string Regular::getColor() const { return colorGroup; }

Utility::Utility() {
	ownBoth = false;
}
Utility::Utility(string locName, int price) {
	name = locName;
	this->price = price;
}

int Utility::calculateRent(int diceTotal) {
	int rent;
	rent = (checkOwnBoth()) ? (diceTotal * 10) : (diceTotal * 4);
	return rent;
}
void Utility::setOwnBoth(bool bothOwned) { ownBoth = true; }
bool Utility::checkOwnBoth() const { return ownBoth; }
Railroad::Railroad() {
	numOwned = 0;
}

Railroad::Railroad(string name) {
	numOwned = 0;
	this->name = name;
}
int Railroad::calculateRent() {
	int rent;
	if (getNumOwned() == 1) { rent = 25; }
	else if (getNumOwned() == 2) { rent = 50; }
	else if (getNumOwned() == 3) { rent = 100; }
	else if (getNumOwned() == 4) { rent = 200; }
	return rent;
}
void Railroad::setNumOwned(int numOwn) { numOwned = numOwn; }
int Railroad::getNumOwned() const { return numOwned; }
