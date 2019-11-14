#include "Player.h"
#include <string>
#include <iostream>
using namespace std;

Player::Player() {
	name = "none";
}
string Player::getName() const { return name; }
void Player::setName(string playerName) { name = playerName; }
int Player::die_roll() {
	int die_Value;
	die_Value = (rand() % 6 + 1);//random number in range 1 to 6
	return die_Value;
}
void Player::takeTurn() {
	bool isDoubles = false;
	int userChoice;
	do {
		cout << "Options:" << endl
			<< "1. Roll dice" << endl
			<< "2. Display property" << endl
			<< "3. Buy houses" << endl;
		cout << "Select an option (1-3): ";
		cin >> userChoice;
		if (userChoice == 1) { //roll dice
			int die1 = die_roll();
			int die2 = die_roll();
			if (die1 == die2) { isDoubles = true; }
			int totalRoll = die1 + die2;
			cout << "You rolled: " << die1 << " and " << die2 << endl
				<< "Move " << totalRoll << " spaces" << endl;
			cout << "You landed on "; //time to add locations
			cout << endl;
		}
		else if (userChoice == 2) { /*display property*/ }
		else if (userChoice == 3) { /*buy houses*/ }
		else {}
	} while (isDoubles);
}