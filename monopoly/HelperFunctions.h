#pragma once
#include "Location.h"
#include "Player.h"
#include <vector>
#include <queue>


vector<Location*> loadBoard();

queue<Player*> initializePlayers();

bool bankrupt(queue<Player*> players, int numPlayers);