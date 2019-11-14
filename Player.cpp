#include "Player.h"
#include "Location.h"
// #include "CardAction.h"
#include <map>
#include <string>
#include <iostream>
using namespace std;

Player::Player() {
	name = "none";
	current_location = 0;
}

Player::Player(string Name) {
	name = Name;
}

string Player::getName() { return name; }

int Player::getCurrentLocation() const { return current_location; }
void Player::setCurrentLocation(int value) { current_location = value; }
void Player::setName(string playerName) { name = playerName; }
void Player::addProperty(Location* newTile) {
	ownedProperties.push_back(newTile);
}

int Player::die_roll() {
	int die_Value;
	die_Value = (rand() % 6 + 1);//random number in range 1 to 6
	return die_Value;
}
void Player::takeTurn(map<int, Location*> &GameBoard, vector<Player*> players) {
	bool isDoubles = false;
	int userChoice, newLocation;
	do {
		//cout << "Options:" << endl
		//	<< "1. Roll dice" << endl
		//	<< "2. Display property" << endl
		//	<< "3. Buy houses" << endl;
		//cout << "Select an option (1-3): ";
		// cin >> userChoice;
		//if (userChoice == 1) { //roll dice
			int die1 = die_roll();
			int die2 = die_roll();
			if (die1 == die2) { isDoubles = true; }
			else { isDoubles = false; }
			int totalRoll = die1 + die2;
			cout << "You rolled: " << die1 << " and " << die2 << endl
				<< "Move " << totalRoll << " spaces" << endl;
			int addVal = getCurrentLocation() + totalRoll;
			cout << getCurrentLocation() << endl;
			newLocation = (addVal <= 39) ? addVal : (addVal - 39); /* Current location plus die roll but wrap around after 40*/
			setCurrentLocation(newLocation);
			cout << "You landed on " << GameBoard.at(getCurrentLocation())->getName() << endl;

			Location* currentTile = GameBoard.at(newLocation);

			if (currentTile->getType() == "Regular") {
				Regular* currentTile = dynamic_cast<Regular*> (GameBoard.at(newLocation));
				// Regular* currentTile = dynamic_cast<Regular*> (currentTile);
				if (currentTile->getOwner() > 0) {
					cout << "This Property is currently owned." << endl;
					// check if current player owns it
					bool currentlyOwned = false;
					for (int i = 0; i < ownedProperties.size(); ++i) {
						if (ownedProperties.at(i)->getName() == currentTile->getName()) {
							currentlyOwned = true;
							cout << "You own it!" << endl;
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
						playerBank.decrementBalance(currentTile->getRent());
						players.at(currentTile->getOwner() - 1)->playerBank.incrementBalance(currentTile->getRent());
					}

				}
				else {
					// print tile information
					cout << "Do you want to buy this property? Enter 1.Yes or 2.No" << endl;
					cin >> userChoice;
					if (userChoice == 1) {
						this->addProperty(currentTile);
						playerBank.decrementBalance(currentTile->getHPrice());
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
			cout << endl;
		//}
		//else if (userChoice == 2) { /*display property*/ }
		//else if (userChoice == 3) { /*buy houses*/ }
		//else {}
	} while (isDoubles);
}