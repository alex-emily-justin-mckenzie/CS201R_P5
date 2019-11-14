#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Player.h"
using namespace std;
bool bankrupt(vector<Player> players, int numPlayers);
int main() {
	int numPlayers;
	vector<Player> players;
	Player currentPlayer;
	string playerName;
	int turnNum = 0;
	srand(time(0));
	cout << "Welcome to Monopoly!" << endl;
	cout << "How many players? (2-4): "; //add # verify
	cin >> numPlayers;
	cin.ignore();
	cout << endl;
	for (unsigned int i = 0; i < numPlayers; ++i) {
		cout << "Enter Player " << i + 1 << "'s name: ";
		getline(cin, playerName);
		currentPlayer.setName(playerName);
		players.push_back(currentPlayer);
	}
	cout << endl;
	//turn
	while (!bankrupt(players, numPlayers)) { //run until only 1 player has bank $
		cout << players.at(turnNum).getName() << "'s turn" << endl;
		cout << players.at(turnNum).getName() << " balance: $ "
			<< players.at(turnNum).playerBank.getBalance() << endl;

		players.at(turnNum).takeTurn();
		
		turnNum += (turnNum == numPlayers - 1) ? (1 - numPlayers) : 1;
	}
}
bool bankrupt(vector<Player> players, int numPlayers) {
	int numBankrupt = 0;
	for (unsigned int i = 0; i < players.size(); ++i) {
		if (!players.at(i).playerBank.getBalance()) {
			numBankrupt += 1;
		}
	}
	if (numBankrupt >= numPlayers - 1) { return true; }
	else { return false; }
}