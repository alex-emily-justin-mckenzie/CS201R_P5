#pragma once
#include "Start.h"
#include <vector>
#include <map>
#include <ctime>
#include <iostream>
#include <fstream>
#include "Player.h"
#include "Location.h"
using namespace std;

vector<Player> initializePlayers(int& numPlayers, int& turnNum);
map<int, Location> loadBoard();