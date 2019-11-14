#pragma once
#include "Location.h"

class CommunityChest : public Location {
public:
	void GetChestCard();
	CommunityChest() {
		tileName = "none";
		type = "Community Chest";
	}
};
