#include "Start.h"
#include <vector>
#include <map>
#include <ctime>
#include <iostream>
#include <fstream>
#include "Player.h"
#include "Location.h"
using namespace std;

map<int, Location> loadBoard() {
	map<int, Location> board;
	ifstream tileRead;
	string tileName, tileType;
	int tileNum;

	tileRead.open("Tiles.txt");
	if (!tileRead) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}
	while(!tileRead.eof()) {
		tileRead >> tileNum;
		tileRead.ignore();
		getline(tileRead, tileName, '\t');
		getline(tileRead, tileType);
		Location currentTile(tileName, tileType);
		board.emplace(tileNum, currentTile);
	}
	tileRead.close();
	return board;
}
vector<Player> initializePlayers(int& numPlayers, int& turnNum) {
	vector<Player> players;
	Player currentPlayer;
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
		currentPlayer.setName(playerName);
		players.push_back(currentPlayer);
	}
	cout << endl;
	return players;
}
