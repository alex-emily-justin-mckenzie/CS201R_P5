#pragma once
#include <string>
using namespace std;
class Location {
public:
	Location();
	Location(string locName, string locType);
	virtual ~Location();
	string getName() const;
	string getType() const;
	string name;
	string type;

};

/* Location has 4 derived classes: Property, Chance/CC, Corner, and Tax*/
class Property : public Location {
public:
	Property();
	Property(int buyPrice, int ownedBy = 0);
	virtual ~Property() ;
	int getPrice() const;
	int getOwner() const;
	void setOwner(int playerNum);
protected:
	int price; //cost to buy
	int owner; //0 for bank, 1-4 for player
};

class Corner : public Location {
public:
	Corner() {};
	Corner(string name);
};

class ChanceCC: public Location {
public:
	ChanceCC() {};
	ChanceCC(string name);
};

class Tax : public Location {
public:
	Tax() {};
	Tax(string name);
};
/* Property has 3 derived classes: Regular, Utility, and Railroad*/
class Regular : public Property {
public:
	Regular(string name, int Rent, int H1Rent, int H2Rent, int H3Rent, int H4Rent, int H5Rent, int HPrice, string Color);
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
	Utility(string locName, int price);
	int calculateRent(int diceTotal);
	void setOwnBoth(bool bothOwned);
	bool checkOwnBoth() const;
private:
	bool ownBoth;
};

class Railroad : public Property {
public:
	Railroad();
	Railroad(string name);
	int calculateRent();
	void setNumOwned(int numOwn);
	int getNumOwned() const;
private:
	int numOwned;
};