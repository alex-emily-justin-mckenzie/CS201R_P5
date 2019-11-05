#pragma once
#include "baseLocationHeader.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

class basePlayer {

private:
	string playerName;
	int money;
	bool inJail = false;

public:
	//Setters + Getters
	string getPlayerName() { return playerName; }
	int getPlayerMoney() { return money; }

	int diceRoll();//roll 2 dice for current player
	void buyProperty(class property);//purchase a house for current tile player is one
	void playerMove();//move player position on board
	void checkBalance();//check current player's balance
	bool goToJail() { inJail = true; }//send player to jail


};