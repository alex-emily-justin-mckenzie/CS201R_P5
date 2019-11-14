#pragma once
#include "Location.h"
#include <vector>
#include "basePlayerHeader.h"
#include <queue>


vector<Location*> loadBoard();

queue<player*> initializePlayers();