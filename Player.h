#pragma once
#include "Bank.h"
#include <string>
using namespace std;

class Player {
public:
	Player();
	string getName() const;
	void setName(string playerName);
	Bank playerBank;
	void takeTurn();
private:
	string name;
	int die_roll();
};