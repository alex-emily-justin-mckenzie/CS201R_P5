#pragma once
#include "Location.h"
#include "Player.h"
#include <vector>
#include <queue>


vector<Location*> loadBoard();

vector<Player*> initializePlayers();

bool bankrupt(vector<Player*> players, int numPlayers);