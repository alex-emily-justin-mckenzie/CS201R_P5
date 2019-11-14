#pragma once
using namespace std;

class Bank {
public:
	Bank();
	int getBalance();
	void incrementBalance(int value);
	void decrementBalance(int value);
	int balance;
};