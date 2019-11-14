#include "Start.h"
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Player.h"
#include "Location.h"
using namespace std;

vector<Location*> loadBoard() {
	vector<Location*> board;
	ifstream tileRead;
	string tileName, tileType;
	int tileNum;

	tileRead.open("tiles.csv");
	if (!tileRead) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}
	while(!tileRead.eof()) {
		string temp, type, name, group, temptileNum;
		getline(tileRead, temp);
		istringstream tempString(temp);

		getline(tempString, temptileNum, ',');
		stringstream getInt(temptileNum);
		getInt >> tileNum;
		getInt.clear();
		getline(tempString, name, ',');
		getline(tempString, type, ',');


		if (type == "Regular") {
			string sPrice, sRent, sHouse1Rent, sHouse2Rent, sHouse3Rent, sHouse4Rent, sHotelRent, sHouseCost, sMortgage;
			int price, rent, house1Rent, house2Rent, house3Rent, house4Rent, hotelRent, houseCost, mortgage;

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


			Regular* currentTile = new Regular(name, rent, house1Rent, house2Rent, house3Rent, house4Rent, hotelRent, houseCost, group);

			board.push_back(currentTile);

		}



		else if (type == "Utility") {
			string sPrice;
			int price;

			getline(tempString, sPrice, ',');

			stringstream getInt(sPrice);
			getInt >> price;
			getInt.clear();

			Utility* currentTile = new Utility(name, price);

			board.push_back(currentTile);
		}

		else if (type == "Railroad") {
			string sPrice;
			int price;

			getline(tempString, sPrice, ',');

			stringstream getInt(sPrice);
			getInt >> price;
			getInt.clear();

			Railroad* newRailroad = new Railroad(name);

			board.push_back(newRailroad);
		}

		else if (type == "Corner") {
			Corner* currentTile = new Corner(name);
			board.push_back(currentTile);
		}

		else if (type == "Chance/CC") {
			ChanceCC* currentTile = new ChanceCC(name);
			board.push_back(currentTile);
		}
		else if (type == "Tax") {
			Tax* currentTile = new Tax(name);
			board.push_back(currentTile);
		}
	}

	tileRead.close();
	return board;
}

vector<Player*> initializePlayers(int& numPlayers, int& turnNum) {
	vector<Player*> players;
	Player* currentPlayer = nullptr;
	string playerName;
	srand(time(0));
	cout << "Welcome to Monopoly!" << endl;
	cout << "How many players? (2-4): "; //add # verify
	cin >> numPlayers;
	cin.ignore();
	cout << endl;
	for (int i = 0; i < numPlayers; ++i) {
		cout << "Enter Player " << i + 1 << "'s name: ";
		getline(cin, playerName);
		currentPlayer = new Player(playerName);
		players.push_back(currentPlayer);
	}
	cout << endl;
	return players;
}
