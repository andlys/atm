#pragma once
#include "Money.h"
#include <string>

using namespace std;

class Account {
private:
	const string _cardNumber;
	string _fullName;
	string _phoneNumber;
	Money _balance;
public:
	Account();
	~Account();
	//TODO getters and setters
	bool changePIN(const string, const string);
};

