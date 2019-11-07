#include "Property.h"

Property::Property(string name, int price, int rent) {
	tileName = name;
	basePrice = price;
	baseRent = rent;
	// houseCost = cost;
	propertyOwned = false;
	// numHotels = numHotels;
}