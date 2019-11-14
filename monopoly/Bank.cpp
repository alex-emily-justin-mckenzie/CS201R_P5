#include "Bank.h"
#include <vector>
#include <queue>
#include "Player.h"

using namespace std;

Bank::Bank() {
}

// Bank::Bank(queue<Player*> players) {
//	 cout << players.size() << " ";
//	 Player* currentPlayer;
//	for (int i = 0; i < players.size(); ++i) {
//		cout << i << " ";
//		currentPlayer = players.front();
//		bankPlayers.push_back(currentPlayer);
//		players.pop();
//		players.push(currentPlayer);
//	}
//}

 //void Bank::PrintPlayers() {
	// for (int i = 0; i < bankPlayers.size(); ++i) {
	//	 cout << bankPlayers.at(i)->getName() << endl;
	// }
 //}

//int Bank::getBalance() const { return balance; }
//void Bank::incrementBalance(int value) { balance += value; }
//void Bank::decrementBalance(int value) { balance -= value; }