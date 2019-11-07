#include "HelperFunctions.h"
#include <fstream>
#include <string>
#include <sstream>
#include "Property.h"
#include "Utilities.h"
#include "Railroad.h"
#include "Chance.h"
#include "CommunityChest.h"


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
				string sPrice, sRent, sHouseCost1, sHouseCost2, sHouseCost3, sHouseCost4, sHotelCost, sMortgage;
				int price, rent, houseCost1, houseCost2, houseCost3, houseCost4, hotelCost, mortgage;

				getline(tempString, name, ',');
				getline(tempString, sPrice, ',');
				getline(tempString, sRent, ',');
				getline(tempString, sHouseCost1, ',');
				getline(tempString, sHouseCost2, ',');
				getline(tempString, sHouseCost3, ',');
				getline(tempString, sHouseCost4, ',');
				getline(tempString, sHotelCost, ',');
				getline(tempString, sMortgage, ',');
				getline(tempString, group);

				// works for now but could be cleaned up
				stringstream getInt(sPrice);
				getInt >> price;
				getInt.clear();
				getInt.str(sRent);
				getInt >> rent;
				getInt.clear();
				getInt.str(sHouseCost1);
				getInt >> houseCost1;
				getInt.clear();
				getInt.str(sHouseCost2);
				getInt >> houseCost2;
				getInt.clear();
				getInt.str(sHouseCost3);
				getInt >> houseCost3;
				getInt.clear();
				getInt.str(sHouseCost4);
				getInt >> houseCost4;
				getInt.clear();
				getInt.str(sMortgage);
				getInt >> mortgage;
				getInt.clear();

				Property* newProperty = new Property(name, price, rent);

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