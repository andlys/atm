#pragma once
#include "Action.h"
#include "Banknote.h"
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::ostream;
using std::endl;

class BanknoteManager;

class MoneyDisposal : public Action {
	friend BanknoteManager;
private:
	vector<Banknote> _banknotes;
	string _message;
	MoneyDisposal(const vector<Banknote> banknotes, const string message = "Successful Withdrawal");
	const string do_toString() const {
		return "TODO toString on MoneyDisposal!!";
	}
public:
	~MoneyDisposal();
	inline const string message() const { return _message; };
	const vector<Banknote>& banknotes() const { return _banknotes; };
};

inline ostream& operator<<(ostream &os, const MoneyDisposal &md);


