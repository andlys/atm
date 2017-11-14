#pragma once
#include "Money.h"
#include "Account.h"
#include "Action.h"

class Transfer : Action {
  friend class Bank;
private:
	Account* _from;
	Account* _to;
	Money _amount;
	//TODO DATE _date
  bool _success;
public:
	Transfer();
	~Transfer();
  bool isSuccessful() const { return _success; }
  const string& toString() const;
};
