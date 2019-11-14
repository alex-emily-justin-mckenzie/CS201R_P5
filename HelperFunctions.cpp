#include "HelperFunctions.h"
#include "basePlayerHeader.h"
#include <fstream>
#include <string>
#include <sstream>
#include "Property.h"
#include "Utilities.h"
#include "Railroad.h"
#include "Chance.h"
#include "CommunityChest.h"
#include <queue>


using namespace std;

vector<Location*> loadBoard() {
	vector<Location*> boardLocations;
	ifstream propertyRead("PropertiesFile.csv");
	// read in file that contains information for all of the tiles in the order they appear on the board
	if (propertyRead.is_open()) {
		while (!propertyRead.eof()) {
			// Load in type of location and then continue stream depending on the type
			string temp;
			string type;

			getline(propertyRead, temp);
			istringstream tempString(temp);
			getline(tempString, type, ',');

			if (type == "Property") {
				string name, group;
				string sPrice, sRent, sHouse1Rent, sHouse2Rent, sHouse3Rent, sHouse4Rent, sHotelRent, sHouseCost, sMortgage;
				int price, rent, house1Rent, house2Rent, house3Rent, house4Rent, hotelRent, houseCost, mortgage;

				getline(tempString, name, ',');
				getline(tempString, sPrice, ',');
				getline(tempString, sRent, ',');
				getline(tempString, sHouse1Rent, ',');
				getline(tempString, sHouse2Rent, ',');
				getline(tempString, sHouse3Rent, ',');
				getline(tempString, sHouse4Rent, ',');
				getline(tempString, sHotelRent, ',');
				getline(tempString, sHotelRent, ',');
				getline(tempString, sMortgage, ',');
				getline(tempString, sHouseCost, ',');
				getline(tempString, group);

				// works for now but could be cleaned up
				stringstream getInt(sPrice);
				getInt >> price;
				getInt.clear();
				getInt.str(sRent);
				getInt >> rent;
				getInt.clear();
				getInt.str(sHouse1Rent);
				getInt >> house1Rent;
				getInt.clear();
				getInt.str(sHouse2Rent);
				getInt >> house2Rent;
				getInt.clear();
				getInt.str(sHouse3Rent);
				getInt >> house3Rent;
				getInt.clear();
				getInt.str(sHouse4Rent);
				getInt >> house4Rent;
				getInt.clear();
				getInt.str(sHotelRent);
				getInt >> hotelRent;
				getInt.clear();
				getInt.str(sHouseCost);
				getInt >> houseCost;
				getInt.clear();
				getInt.str(sMortgage);
				getInt >> mortgage;
				getInt.clear();

				PropertyRent newPropRent(rent, house1Rent, house2Rent, house3Rent, house4Rent, hotelRent);
				Property* newProperty = new Property(name, price, houseCost, newPropRent, mortgage, group);

				boardLocations.push_back(newProperty);
			}

			else if (type == "Special") {

			}

			else if (type == "Community Chest") {
				CommunityChest* newChest = new CommunityChest;
				boardLocations.push_back(newChest);
			}

			else if (type == "Chance") {
				Chance* newChance = new Chance;
				boardLocations.push_back(newChance);
			}

			else if (type == "Utilities") {
				string name, sPrice;
				int price;

				getline(tempString, name, ',');
				getline(tempString, sPrice, ',');

				stringstream getInt(sPrice);
				getInt >> price;
				getInt.clear();

				Utilities* newUtility = new Utilities(name, price);

				boardLocations.push_back(newUtility);
			}

			else if (type == "Railroad") {
				string name, sPrice;
				int price;

				getline(tempString, name, ',');
				getline(tempString, sPrice, ',');

				stringstream getInt(sPrice);
				getInt >> price;
				getInt.clear();

				Railroad* newRailroad = new Railroad(name, price);

				boardLocations.push_back(newRailroad);
			}

			else {
				// Error Handling to be done !
			}
		}
	}

	return boardLocations;

}


// set up a queue of players, ask how many and their names, give them starting money

queue<player*> initializePlayers() {
	queue<player*> players;
	int numPlayers;
	string tempName;
	cout << "How many players?" << endl;
	cin >> numPlayers;

	for (int i = 0; i < numPlayers; ++i) {
		cout << "What is the name of Player " << i + 1 << endl;
		cin >> tempName;
		// Error handling here?
		player* newPlayer = new player(tempName);
		players.push(newPlayer); // will need to rethink if we want to order the queue based on initial dice roll
	}
	return players;
}
