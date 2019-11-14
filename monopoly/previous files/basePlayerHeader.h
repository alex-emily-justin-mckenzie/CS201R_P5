#pragma once
#include "Location.h"
#include "Property.h"
#include <string>
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

class player {

private:
	string name;
	int money;
	bool inJail = false;
	vector<Location*> ownedProperties;
	Location* currentLocation;

public:
	player(string name);
	//Setters + Getters
	string getPlayerName() { return name; }
	int getPlayerMoney() { return money; }

	int diceRoll();//roll 2 dice for current player
	void buyHouse(Property propName);//purchase a house for current tile player is one
	void buyProperty();
	void playerMove();//move player position on board
	void checkBalance();//check current player's balance
	bool goToJail() { inJail = true; }//send player to jail
	void PayBank(int amount);
	void ReceivePayment(int amount);
};