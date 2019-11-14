#pragma once
using namespace std;

class Bank {
public:
	Bank();
	int getBalance() const;
	void incrementBalance(int value);
	void decrementBalance(int value);
private:
	int balance;
};