#pragma once
#include "Location.h"

class Chance : public Location {
public:
	void GetChanceCard();
	Chance() {
		tileName = "none";
		type = "Chance";
	}
};