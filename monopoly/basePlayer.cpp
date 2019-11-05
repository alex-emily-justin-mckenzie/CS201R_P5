#include "basePlayerHeader.h"

//this shit is going to be more complicated than I thought
//we need to move the player for every individual roll if they do roll double or triple 
//maybe call playerMove() in between separate rolls 
//or just simplify it and call it multiple times in main might be easiest
int basePlayer::diceRoll()
{
	int diceTotal=0;
	bool doubleRolled=false;
	int numDoubleRolled=0;
	int tempDice=0;//stores the first dice roll for double roll cases
	for (int i = 0; i < 2; i++)
	{
		int diceRoller = 1 + rand() % 6;
		if (tempDice == diceRoller)
		{
			cout << "You have rolled a double! Roll again." << endl;
		}
		diceTotal += diceRoller;
		tempDice = diceRoller;
	}
	return diceTotal;
}

void basePlayer::buyProperty(class property location)
{ 
	//check to see if anyone owns the property so player can buy or not
	if (location.getIfOwned() == false)
	{
		char tempChoice;
		cout << "Property currently has no owner!" << endl;
		cout << "Cost to buy property on current tile: " << location.getHouseCost() << endl;

		//check to make sure player has enough money to buy the property.
		if (money < location.getHouseCost())
		{
			cout << "You do not have enough money to afford this house. I smell broke?" << endl;
		}

		cout << "Would you like to buy the property? Y/N?" << endl;
		cin >> tempChoice;
		if (tempChoice == 'y' || tempChoice == 'Y')
		{
			cout << "Congratulations on your new property: " << location.getLocationName() << endl;
			money -= location.getHouseCost();
		}
		if (tempChoice == 'n' || tempChoice == 'N')
		{
			cout << "I knew you wouldn't buy it." << endl;
		}
	}
}

void basePlayer::checkBalance()
{
	cout << "Your current balance is: $" << money << endl;
}
