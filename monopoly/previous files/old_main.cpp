#include "Location.h"
// #include "basePlayerHeader.h"
#include "HelperFunctions.h"
#include "Property.h"
#include <sstream>
#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;
/*
Monopoly Rules:
// How is the game actually supposed to end??

*/
int main() {
	vector<Location*> board;
	queue<player*> players; 
	player* currentPlayer;
	// at the start of the player's turn you pop them out of the queue, then at the end of their turn you pop them back into the queue

	players = initializePlayers();

	board = loadBoard();

	
	// Check:
	for (int i = 0; i < board.size(); ++i) {
		cout << board.at(i)->getTileName() << endl;
	}

	return 0;
}

