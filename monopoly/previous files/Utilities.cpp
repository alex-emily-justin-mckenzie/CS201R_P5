#include "Utilities.h"

int Utilities::CalculateRent(int diceTotal, int numUtilOwned) {
	int rent;
	if (numUtilOwned == 1) {
		rent = diceTotal * 4;
	}
	else {
		rent = diceTotal * 10;
	}
	return rent;
}