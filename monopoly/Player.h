#pragma once
// #include "Bank.h"
#include <string>
#include <vector>
#include "Location.h"
#include "Property.h"

using namespace std;

class Player {

private:
	string name;
	int money;
	bool inJail = false;
	vector<Location*> ownedProperties;
	int currentLocation;
	int die_roll();


public:
	Player(string name);
	//Setters + Getters
	string getPlayerName() { return name; }
	int getPlayerMoney() { return money; }

	//int diceRoll();//roll 2 dice for current player
	//void buyHouse(Property propName);//purchase a house for current tile player is one
	//void buyProperty();
	//void playerMove();//move player position on board
	void checkBalance();//check current player's balance
	bool goToJail() { inJail = true; }//send player to jail
	//void PayBank(int amount);
	//void ReceivePayment(int amount);

	Player();
	string getName() const;
	void setName(string playerName);
	// Bank playerBank;
	void takeTurn(vector<Location*> board);

};