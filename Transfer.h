#pragma once
#include "Money.h"
#include "Account.h"
#include "Action.h"
#include "lib/fmt-4.0.0/fmt/format.h"
#include "lib/fmt-4.0.0/fmt/printf.h"

using std::string;

class Transfer : public Action {
  friend class Bank;
private:
	Account* _from;
	Account* _to;
	const Money _amount;
    //TODO DATE _date // TODO delete this comment since date is already present in Action
    bool _success;
	// It seems better to return just string.
	//const string& toString() const;
	const string do_toString() const {
        // TODO money has currency type ???
		return fmt::format("Transfer {6}: #{0} ({1}) sent {2} {5} to #{3} ({4})",
            _from->cardNumber(), _from->fullName(), double(_amount),
            _to->cardNumber(),   _to->fullName(), _amount.code(),
            isSuccessful() ? "(success)" : "(failure)");
	}

public:
	Transfer(Account*, Account*, const Money&);
	~Transfer();
	bool isSuccessful() const { return _success; }

	Account* from() const { return _from; }
	Account* to() const { return _to; }
	const Money amount() const { return _amount; }

};
