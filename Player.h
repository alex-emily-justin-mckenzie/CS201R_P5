#pragma once
#include "Bank.h"
#include "Location.h"
#include <map>
#include <string>
using namespace std;

class Player {
public:
	Player();
	string getName() const;
	int getCurrentLocation() const;
	void setName(string playerName);
	Bank playerBank;
	void takeTurn(map<int, Location>& GameBoard);
	void setCurrentLocation(int value);
private:
	string name;
	int current_location;
	int die_roll();
};