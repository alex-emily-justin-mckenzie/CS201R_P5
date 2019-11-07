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


*/
int main() {
	vector<Location*> board;
	board = loadBoard();

	for (int i = 0; i < board.size(); ++i) {
		cout << board.at(i)->getTileName() << endl;
	}


	return 0;

}

