#pragma once
#include <string>
using namespace std;
class Location {
public:
	Location();
	Location(string locName, string locType);
	string getName() const;
	string getType() const;
private:
	string name;
	string type;
};
/* Location has 4 derived classes: Property, Chance/CC, Corner, and Tax*/
class Property : public Location {
public:
	Property();
	Property(int buyPrice, int ownedBy = 0);
	int getPrice() const;
	int getOwner() const;
	void setOwner(int playerNum);
private:
	int price; //cost to buy
	int owner; //0 for bank, 1-4 for player
};
/* Property has 3 derived classes: Regular, Utility, and Railroad*/
class Regular : public Property {
public:
	Regular(int Rent, int H1Rent, int H2Rent, int H3Rent, int H4Rent, int H5Rent, int HPrice, string Color);
	int getRent() const;
	int getH1Rent() const;
	int getH2Rent() const;
	int getH3Rent() const;
	int getH4Rent() const;
	int getH5Rent() const;
	int getHPrice() const;
	string getColor() const;
private:
	int rent;
	int house1Rent;
	int house2Rent;
	int house3Rent;
	int house4Rent;
	int hotelRent;
	int housePrice;
	string colorGroup;
};
class Utility : public Property {
public:
	Utility();
	int calculateRent(int diceTotal);
	void setOwnBoth(bool bothOwned);
	bool checkOwnBoth() const;
private:
	bool ownBoth;
};
class Railroad : public Property {
public:
	Railroad();
	int calculateRent();
	void setNumOwned(int numOwn);
	int getNumOwned() const;
private:
	int numOwned;
};