#include "Property.h"

PropertyRent::PropertyRent(int baseRent, int house1Rent, int house2Rent, int house3Rent, int house4Rent, int hotelRent) {
	this->baseRent = baseRent;
	this->house1Rent = house1Rent;
	this->house2Rent = house2Rent;
	this->house3Rent = house3Rent;
	this->house4Rent = house4Rent;
	this->hotelRent = hotelRent;
}

Property::Property(string name, int price, int housePrice, PropertyRent rentLevels, int mortgage, string group) {
	tileName = name;
	basePrice = price;
	propertyOwned = false;
	currentRent = rentLevels.baseRent;
	this->mortgage = mortgage;
	this->rentLevels = rentLevels;
	this->housePrice = housePrice;
	type = "Property";
	this->group = group;
	tileOwner = "none";
}