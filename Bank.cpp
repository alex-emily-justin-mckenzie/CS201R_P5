#include "Bank.h"

Bank::Bank() {
	balance = 1500;
}
int Bank::getBalance() const { return balance; }
void Bank::incrementBalance(int value) { balance += value; }
void Bank::decrementBalance(int value) { balance -= value; }