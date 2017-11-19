#pragma once
#include "MoneyDisposal.h"
#include <vector>
#include <map>
using namespace std;
class BanknoteManager {
private:
	//first - nominal, second - list of Banknotes
	map<int, vector<Banknote>> _available;

	vector<int> amounts() const {
		vector<int> amount;
		for (auto it = _available.rbegin(); it != _available.rend(); ++it) {
			amount.push_back(it->second.size());
		}
		return amount;
	};

	vector<Banknote> banknotes(vector<int> nominals) {
		vector<Banknote> banknotesRes;
		int i = 0;
		for (auto it = _available.rbegin(); it != _available.rend(); ++it) {
			for (int j = 0; j < nominals[i]; ++j) {
				banknotesRes.push_back(Banknote{ it->second[(it->second.size() - 1)]._nominal, it->second[(it->second.size() - 1)]._code, it->second[(it->second.size() - 1)]._id });
				it->second.pop_back();
			}
			++i;
		}
		return banknotesRes;
	}

	bool enoughMoney(const unsigned int cash) {
		unsigned int sumAllMoney = 0;
		for (auto it = _available.begin(); it != _available.end(); ++it) {
			for (int j = 0; j < it->second.size(); ++j) {
				sumAllMoney += it->second[j]._nominal;
			}
		}
		return sumAllMoney >= cash;
	};

	vector<vector<int>> solutions(const vector<int> values, const vector<int> amounts, const vector<int> variation, unsigned int price, int position) {
		vector<vector<int>> list;
		int value = compute(values, variation);
		if (value < price) {
			for (int i = position; i < values.size(); i++) {
				if (amounts[i] > variation[i]) {
					vector<int> newVariation = variation;
					newVariation[i]++;
					vector<vector<int>> newList = solutions(values, amounts, newVariation, price, i);
					if (!newList.empty()) {
						list.insert(list.end(), newList.begin(), newList.end());
						break;
					}
				}
			}
		} else if (value == price) {
			list.push_back(myCopy(variation));
		}
		return list;
	}

	int compute(const vector<int> values, const vector<int> variation) {
		int ret = 0;
		for (int i = 0; i < variation.size(); i++) {
			ret += values[i] * variation[i];
		}
		return ret;
	}

	vector<int> myCopy(const vector<int> ar) {
		vector<int> ret(ar.size());
		for (int i = 0; i < ar.size(); i++) {
			ret[i] = ar[i];
		}
		return ret;
	}



public:
	BanknoteManager() : _available({
		{ 500, vector<Banknote> { Banknote{ 500, "", "" } } },
		{ 200, vector<Banknote> { Banknote{ 200, "", "" }, Banknote{ 200, "", "" } } },
		{ 100, vector<Banknote> { Banknote{ 100, "", "" }, Banknote{ 100, "", "" }, Banknote{ 100, "", "" } } },
		{ 50, vector<Banknote> { Banknote{ 50, "", "" }, Banknote{ 50, "", "" }, Banknote{ 50, "", "" }, Banknote{ 50, "", "" } } },
		{ 20, vector<Banknote> { Banknote{ 20, "", "" }, Banknote{ 20, "", "" }, Banknote{ 20, "", "" }, Banknote{ 20, "", "" }, Banknote{ 20, "", "" } } },
		{ 10, vector<Banknote> { Banknote{ 10, "", "" }, Banknote{ 10, "", "" }, Banknote{ 10, "", "" }, Banknote{ 10, "", "" }, Banknote{ 10, "", "" }, Banknote{ 10, "", "" } } },
		{ 5, vector<Banknote> { Banknote{ 5, "", "" }, Banknote{ 5, "", "" }, Banknote{ 5, "", "" }, Banknote{ 5, "", "" }, Banknote{ 5, "", "" }, Banknote{ 5, "", "" }, Banknote{ 5, "", "" } } },
		{ 2, vector<Banknote> { Banknote{ 2, "", "" } } },
		{ 1, vector<Banknote> { } }
	}) {
		return;
	}

	~BanknoteManager() { return; }

	const MoneyDisposal getCash(unsigned int cash) {
		if (!enoughMoney(cash)) {
			return MoneyDisposal(vector<Banknote>{}, "Operation failed: Not Enough Money in ATM");
		}
		////500, 200, 100, 50, 20, 10, 5, 2, 1
		vector<int> values = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
		vector<int> amounts = this->amounts();
		vector<vector<int>> banknotesResult = solutions(values, amounts, vector<int>(values.size()), cash, 0);
		if (banknotesResult.size() == 0) {
			return MoneyDisposal(vector<Banknote>{}, "Operation failed: No such banknotes in ATM");
		}
		vector<Banknote> res = banknotes(banknotesResult[0]);

		return MoneyDisposal(res);
	}
};