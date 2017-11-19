#pragma once
#include "Action.h"
#include "Banknote.h"
#include <vector>
#include <string>

using namespace std;
class BanknoteManager;

class MoneyDisposal : public Action {
	friend BanknoteManager;
private:
	vector<Banknote> _banknotes;
	string _message;
	MoneyDisposal(const vector<Banknote> banknotes, const string message = "Successful Withdrawal") : _banknotes(banknotes), _message(message) {
		return;
	}
	const string do_toString() const {
		return "TODO toString on MoneyDisposal!!";
	}
public:
	~MoneyDisposal() {}
	inline const string message() const { return _message; };
	const vector<Banknote>& banknotes() const { return _banknotes; };
};

ostream& operator<<(ostream &os, const MoneyDisposal &md) {
	os << "|--------------------|" << endl;
	os << "Message: " << md.message() << endl;
	vector<Banknote> bn = md.banknotes();
	if (!md.banknotes().empty())
		os << "----------------------" << endl;
	for (int i = 0; i < bn.size(); ++i) {
		cout << bn[i] << endl;
	}
	os << "|--------------------|" << endl;
	return os;
}
