#include "Location.h"

Location::Location(string tileName, string type) {
	this->tileName = tileName;
	this->type = type;
}


Location::Location() {
	tileName = "none";
	type = "none";
}
