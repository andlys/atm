#pragma once
#include "Money.h"
#include "Account.h"
#include "Action.h"

class Transfer : Action {
  friend class Bank;
private:
	Account* _from;
	Account* _to;
	const Money _amount;
    //TODO DATE _date
    bool _success;
	// It seems better to return just string.
	//const string& toString() const;
	const string do_toString() const {
		return "TODO toString on Transfer!!";
	}
public:
	Transfer(Account*, Account*, const Money);
	~Transfer();
	bool isSuccessful() const { return _success; }

	Account* from() const { return _from; }
	Account* to() const { return _to; }
	const Money amount() const { return _amount; }

};
