#include "Player.h"
#include <string>
#include <iostream>
using namespace std;

Player::Player() {
	name = "none";
	money = 0;
	inJail = false;
}

Player::Player(string name) {
	this->name = name;
	money = 500; // CHECK HOW MUCH THEY START WITH!
	inJail = false;
	// once we figure out how to do the special cards then we can update this to start them at collect 200 and go tile;
}

string Player::getName() const { return name; }

void Player::setName(string playerName) { name = playerName; }

void Player::checkBalance()
{
	cout << "Your current balance is: $" << money << endl << endl;
}

int Player::die_roll() {
	int die_Value;
	die_Value = (rand() % 6 + 1);//random number in range 1 to 6
	return die_Value;
}
void Player::takeTurn(const vector<Location*> board) {
	bool isDoubles = false;
	int userChoice;
	do {

		int die1 = die_roll();
		int die2 = die_roll();
		if (die1 == die2) { isDoubles = true; }
		int totalRoll = die1 + die2;
		cout << "You rolled: " << die1 << " and " << die2 << endl
			<< "Move " << totalRoll << " spaces" << endl;
		int newLocation = currentLocation + totalRoll;
		if (newLocation > 39) {
			newLocation -= 39;
		}

		Location* currentTile = board.at(newLocation);

		cout << "You landed on " << currentTile->getTileName(); // need a print tile method
		cout << endl;

		if (currentTile->getType() == "Property") {
			// check if owned already
			// if owned then they have to pay rent
			// ask if they want to buy it
			// if they own it ask if they want to add a house/hotel 
		}
		else if (currentTile->getType() == "Railroad") {
			// check if owned already
			// if owned then they have to pay rent accordingly
			// if not owned ask if they want to buy it
		}
		else if (currentTile->getType() == "Utilities") {
			// same as above
		}
		else if (currentTile->getType() == "Special") {
			// based on newLocation number, can implement special directions for jail, etc.
		}
		else {
			cout << "Free Space" << endl;
		}

	} while (isDoubles);
}