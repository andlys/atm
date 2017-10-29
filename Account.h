#pragma once
#include "Money.h"
#include "Action.h"
#include <string>
#include <vector>

using namespace std;

class Account {
private:
	const string _cardNumber;
	string _fullName;
	string _phoneNumber;
	Money _balance;
  string _password;
  vector<Action> _history;
public:
	Account();
	~Account();
	//TODO getters and setters
  void updateHistory(const vector<Action>&);
	bool changePIN(const string, const string);
};
