#pragma once
#include "Action.h"
#include "Banknote.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class BanknoteManager;

class MoneyDisposal : Action {
	friend BanknoteManager;
private:
	vector<Banknote> _banknotes;
	bool _success;
	MoneyDisposal(const vector<Banknote> banknotes, const bool success) : _banknotes(banknotes), _success(success) {
		return;
	}
	const string do_toString() const {
		return "TODO toString on MoneyDisposal!!";
	}
public:
	~MoneyDisposal() {}
	inline const bool success() const { return _success; };
	const vector<Banknote>& banknotes() const { return _banknotes; };
};

ostream& operator<<(ostream &os, const MoneyDisposal &md) {
	os << "|--------------------|" << endl;
	os << "Is Success: " << (md.success() ? "Success" : "Fail(Not enough Money in ATM)") << endl;
	vector<Banknote> bn = md.banknotes();
	if (md.success())
		os << "----------------------" << endl;
	for (int i = 0; i < bn.size(); ++i) {
		cout << bn[i] << endl;
	}
	os << "|--------------------|" << endl;
	return os;
}
