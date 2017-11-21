#include "MoneyDisposal.h"

MoneyDisposal::MoneyDisposal(const vector<Banknote> banknotes, const string message) : _banknotes(banknotes), _message(message) {
	return;
}

MoneyDisposal::~MoneyDisposal() {
	return;
}

ostream& operator<<(ostream &os, const MoneyDisposal &md) {
	os << "|--------------------|" << endl;
	os << "Message: " << md.message() << endl;
	vector<Banknote> bn = md.banknotes();
	if (!md.banknotes().empty())
		os << "----------------------" << endl;
	for (int i = 0; i < bn.size(); ++i) {
		os << bn[i] << endl;
	}
	os << "|--------------------|" << endl;
	return os;
}
