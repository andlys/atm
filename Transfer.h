#pragma once
#include "Money.h"
#include "Account.h"
#include "Action.h"

class Transfer : Action {
private:
	Account* _from;
	Account* _to;
	Money _amount;
	//TODO DATE _date
public:
	Transfer();
	~Transfer();
  const string& toString() const;
};
