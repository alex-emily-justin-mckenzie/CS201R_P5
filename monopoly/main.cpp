#include "baseLocationHeader.h"
#include "basePlayerHeader.h"
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
	// Kenzie Comment: I think we should try to use a queue, but then I looked at them and it didn't seem easy to move within?
	vector<property> testProperty;
	ifstream propertyRead("PropertiesFile.csv");
	if (propertyRead.is_open()) {
		while (!propertyRead.eof()) {
			//string tempLocation;
			//int tempBasePrice;
			//int tempRent;
			//int tempHouseCost;
			
			string temp;
			string name;
			string sPrice, sRent, sHouseCost1, sHouseCost2, sHouseCost3, sHouseCost4, sHotel, sMortgage;
			int price, rent, houseCost1, houseCost2, houseCost3, houseCost4, hotel, mortgage;

			string group;

			getline(propertyRead, temp);
			istringstream tempString(temp);

			getline(tempString, name, ',');
			getline(tempString, sPrice, ',');
			getline(tempString, sRent, ',');
			getline(tempString, sHouseCost1, ',');
			getline(tempString, sHouseCost2, ',');
			getline(tempString, sHouseCost3, ',');
			getline(tempString, sHouseCost4, ',');
			getline(tempString, sHotel, ',');
			getline(tempString, sMortgage, ',');
			getline(tempString, group);

			// works for now but could be cleaned up
			stringstream getInt(sPrice);
			getInt >> price;
			getInt.clear();
			getInt.str(sRent);
			getInt >> rent;
			getInt.clear();
			getInt.str(sHouseCost1);
			getInt >> houseCost1;
			getInt.clear();			
			getInt.str(sHouseCost2);
			getInt >> houseCost2;
			getInt.clear();
			getInt.str(sHouseCost3);
			getInt >> houseCost3;
			getInt.clear();
			getInt.str(sHouseCost4);
			getInt >> houseCost4;
			getInt.clear();
			getInt.str(sMortgage);
			getInt >> mortgage;
			getInt.clear();

			property tempProperty;
			tempProperty.setBasePrice(price);
			tempProperty.setRent(rent);
			tempProperty.setHouseCost(houseCost1);
			tempProperty.setLocationName(name);

			testProperty.push_back(tempProperty);

		}
	}


	return 0;

}

