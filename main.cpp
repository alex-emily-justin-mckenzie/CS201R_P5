#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <map>
#include "Player.h"
#include "Location.h"
#include "Start.h"
using namespace std;
bool bankrupt(vector<Player*> players, int numPlayers);
int main() {
	int numPlayers;
	int turnNum = 0;
	vector<Player*> players = initializePlayers(numPlayers, turnNum);
	vector<Location*> GameBoard = loadBoard();
	
	//for (int i = 0; i < GameBoard.size(); ++i) {
	//	cout << i << " " << GameBoard.at(i)->getName() << endl;
	//}
	//for (auto& x:GameBoard) {
	//	cout << x.first << " " << x.second->getName()<< endl;
	//}

	// turn
	while(!bankrupt(players, numPlayers)) { //run until only 1 player has bank $
		cout << players.at(turnNum)->getName() << "'s turn" << endl;
		cout << players.at(turnNum)->getName() << " balance: $ "
			<< players.at(turnNum)->playerBank.getBalance() << endl;

		players.at(turnNum)->takeTurn(GameBoard, players);
		
		turnNum += (turnNum == numPlayers - 1) ? (1 - numPlayers) : 1;
	}
}
bool bankrupt(vector<Player*> players, int numPlayers) {
	int numBankrupt = 0;
	for (unsigned int i = 0; i < players.size(); ++i) {
		if (!players.at(i)->playerBank.getBalance()) {
			numBankrupt += 1;
		}
	}
	if (numBankrupt >= numPlayers - 1) { return true; }
	else { return false; }
}