#include "Player.h"
#include "Location.h"
#include "CardAction.h"
#include <map>
#include <string>
#include <iostream>
using namespace std;

Player::Player() {
	name = "none";
	current_location = 0;
}
string Player::getName() const { return name; }
int Player::getCurrentLocation() const { return current_location; }
void Player::setCurrentLocation(int value) { current_location = value; }
void Player::setName(string playerName) { name = playerName; }
int Player::die_roll() {
	int die_Value;
	die_Value = (rand() % 6 + 1);//random number in range 1 to 6
	return die_Value;
}
void Player::takeTurn(map<int, Location> &GameBoard) {
	bool isDoubles = false;
	int userChoice, newLocation;
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
			else { isDoubles = false; }
			int totalRoll = die1 + die2;
			cout << "You rolled: " << die1 << " and " << die2 << endl
				<< "Move " << totalRoll << " spaces" << endl;
			int addVal = getCurrentLocation() + totalRoll;
			newLocation = (addVal <= 40) ? addVal : (addVal % 40); /* Current location plus die roll but wrap around after 40*/
			setCurrentLocation(newLocation);
			cout << "You landed on " << GameBoard.at(getCurrentLocation()).getName() << endl;
			//cardAction(getCurrentLocation(), GameBoard); //pass GameBoard by reference
			cout << endl;
		}
		else if (userChoice == 2) { /*display property*/ }
		else if (userChoice == 3) { /*buy houses*/ }
		else {}
	} while (isDoubles);
}