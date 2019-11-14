#include "Player.h"
#include <string>
#include <iostream>
using namespace std;

Player::Player() {
	name = "none";
	money = 0;
	inJail = false;
	vector<Location*> ownedProperties;

}

Player::Player(string name) {
	this->name = name;
	money = 500; // CHECK HOW MUCH THEY START WITH!
	inJail = false;
	vector<Location*> ownedProperties;

	// once we figure out how to do the special cards then we can update this to start them at collect 200 and go tile;
}

void Player::decrementMoney(int decrementValue) {
	money -= decrementValue;
}

void Player::incrementMoney(int incrementValue) {
	money += incrementValue;
}

void Player::addProperty(Location* newTile) {
	ownedProperties.push_back(newTile);
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
void Player::takeTurn(const vector<Location*> board, vector<Player*> players) {
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

		cout << "You landed on " << board.at(newLocation)->getTileName(); // need a print tile method
		cout << endl;

		if (currentTile->getType() == "Property") {
			Property* currentTile = dynamic_cast<Property*> (currentTile);
			if (currentTile->getIfOwned()) {
				// check if current player owns it
				bool currentlyOwned = false;
				 for (int i = 0; i < ownedProperties.size(); ++i) {
					 if (ownedProperties.at(i)->getTileName == currentTile->getTileName) {
						 currentlyOwned = true;
					 }
				 }
				 // need to also check if they own the whole group...
				 if (currentlyOwned) {
					 cout << "Do you want to buy a house or a hotel?" << endl;
					 cout << "1. To buy a house" << endl;
					 cout << "2. To buy a hotel" << endl;
					 cout << "3. Don't want to buy anything" << endl;
					 cin >> userChoice;
					 if (userChoice == 1) {
						 // buy a house
						 // update rental rate
					 }
					 else if (userChoice == 2) {
						 // buy a hotel
						 // update rental rate
					 }
				 }
				 else {
					 money -= currentTile->getCurrentRent(); 
					 for (int i = 0; i < players.size(); ++i) {
						 if (currentTile->getOwnerName == players.at(i)->getName) {
							 players.at(i)->incrementMoney(currentTile->getCurrentRent);
						 }
					 }

				 }

			 }
			else {
				// print tile information
				cout << "Do you want to buy this property? Enter 1.Yes or 2.No" << endl;
				cin >> userChoice;
				if (userChoice == 1) {
					this->addProperty(currentTile);
					this->decrementMoney(currentTile->getBasePrice);
				}

			 }

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