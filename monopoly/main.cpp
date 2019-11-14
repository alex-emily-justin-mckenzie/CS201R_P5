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
#include "Bank.h"
using namespace std;
/*
Monopoly Rules:

*/
int main() {
	vector<Location*> board;
	vector<Player*> players; 
	Player* currentPlayer;
	int turnNum = 0;

	players = initializePlayers();
	int numPlayers = players.size();
	board = loadBoard();

	srand(time(0));

	//turn
	while (!bankrupt(players, players.size())) { //run until only 1 player has bank $
		currentPlayer = players.at(turnNum);
		cout << currentPlayer->getName() << "'s turn" << endl;
		currentPlayer->checkBalance();


		currentPlayer->takeTurn(board, players);

		turnNum += (turnNum == numPlayers - 1) ? (1 - numPlayers) : 1;

	}
	

	return 0;
}




