#pragma once
#include "Bank.h"
#include "Location.h"
#include <map>
#include <string>
#include <vector>
using namespace std;

class Player {
public:
	Player();
	Player(string name);
	string getName();
	int getCurrentLocation() const;
	void setName(string playerName);
	Bank playerBank;
	void takeTurn(vector<Location*>& GameBoard, vector<Player*> players);
	void setCurrentLocation(int value);
	void addProperty(Location* newTile);
private:
	string name;
	int current_location;
	int die_roll();
	vector<Location*> ownedProperties;

};