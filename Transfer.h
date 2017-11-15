#pragma once
#include "Money.h"
#include "Account.h"
#include "Action.h"

class Transfer : Action {
  friend class Bank;
private:
	const Account* _from;
	const Account* _to;
	const Money _amount;
    //TODO DATE _date
    bool _success;
public:
	Transfer(const Account*, const Account*, const Money);
	~Transfer();
    bool isSuccessful() const { return _success; }
    
    // It seems better to return just string.
    //const string& toString() const;
    const string toString() const;
};
