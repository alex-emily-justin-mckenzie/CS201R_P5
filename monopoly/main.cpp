#include "Location.h"
#include "HelperFunctions.h"
#include "Property.h"
#include <sstream>
#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <queue>
#include <ctime>
#include "Player.h"
using namespace std;
/*
Monopoly Rules:

*/
int main() {
	vector<Location*> board;
	queue<Player*> players; 
	Player* currentPlayer;

	players = initializePlayers();
	board = loadBoard();

	srand(time(0));

	//turn
	while (!bankrupt(players, players.size())) { //run until only 1 player has bank $
		currentPlayer = players.front();
		players.pop();
		cout << currentPlayer->getName() << "'s turn" << endl;
		currentPlayer->checkBalance();
		currentPlayer->takeTurn();

		players.push(currentPlayer);

		// turnNum += (turnNum == numPlayers - 1) ? (1 - numPlayers) : 1;
	}
	

	return 0;
}




