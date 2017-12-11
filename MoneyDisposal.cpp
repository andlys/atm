#include "MoneyDisposal.h"

MoneyDisposal::MoneyDisposal(const vector<Banknote> banknotes, const string message) : _banknotes(banknotes), _message(message) {
	return;
}

MoneyDisposal::~MoneyDisposal() {
	return;
}

const string MoneyDisposal::do_toString() const {
    string msg("Withdrawn cash: ");
    for (vector<Banknote>::const_iterator it = _banknotes.begin(); it != _banknotes.end(); ++it)
        msg += it->toString() + ", ";
    return msg;
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
