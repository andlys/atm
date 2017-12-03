#pragma once
#include "MoneyDisposal.h"
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

class BanknoteManager {
private:
	//first - nominal, second - list of Banknotes
	map<int, vector<Banknote>> _available;

	vector<int> amounts() const;

	vector<Banknote> banknotes(vector<int> nominals);

	bool enoughMoney(const unsigned int cash);

	vector<vector<int>> solutions(const vector<int> values, const vector<int> amounts, const vector<int> variation, unsigned int price, int position);

	int compute(const vector<int> values, const vector<int> variation);
	vector<int> myCopy(const vector<int> ar);
public:
	BanknoteManager();
	~BanknoteManager();
	const vector<int> availableNominals() const;

	const MoneyDisposal getCash(unsigned int cash);
};
