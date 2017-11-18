#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Bank.h"
#include "Action.h"
#include "Account.h"
#include "Transfer.h"
#include <string>

using namespace std;

struct Banknote {
	const unsigned int _nominal;
	const string _code;
	const string _id;
};

class ATM{
private:
    class Session;
    Session* _currentSession;
    class BanknoteManager;
    BanknoteManager* _banknoteManager;
    Bank* _bank;
    const string _address;
    friend void test_session(void); // TODO comment
public:
    ATM(BanknoteManager&, Bank&);
    ATM(Bank& bank):_currentSession(0),
                _banknoteManager(0),
                _bank(&bank){}
    ~ATM();
    void login(const string&, const string&);
    void logout();
    bool transfer(const string&, const Money&);
    //bool withdrow(const Money&);

};

class ATM::Session {
private:
	vector<const Action*> _history;
	Account* _currentAccount;
	bool writeToFile() {
		for (vector<const Action*>::iterator it = _history.begin(); it != _history.end(); ++it) {
            // TODO send to file
			cout << (*it)->datetimeString() << " - " << (*it)->toString() << endl;
		}
        return false; // TODO
	}
public:
	Session(): _currentAccount(0) {
		return;
	}
	~Session() {
		writeToFile();
        for (vector<const Action*>::iterator it = _history.begin(); it != _history.end(); ++it) {
            delete *it; // TODO remove once we implement smart ptr
        }
		delete _currentAccount;
		return;
	}
	bool setAccount(const Account& account) {
		if (_currentAccount != 0) return false;
		//TODO need copy constuctor
		//_currentAccount(account);
		return true;
	}
	Session& pushToHistory(const Action* action) {
		_history.push_back(action);
		return *this;
	}
  // TODO make destructor invoking writeToFile();
};

// TODO make global
class BanknoteManager {
	typedef int countMoney;
private:
	map<countMoney, vector<Banknote>> _available;
	class MoneyDisposal;
	//const Money& _m;

	vector<int> amounts() const {

	};

	vector<vector<int>> solutions(const vector<int> values, const vector<int> amounts, const vector<int> variation, unsigned int price, int position) {
		vector<vector<int>> list;
		int value = compute(values, variation);
		if (value < price) {
			for (int i = position; i < values.size(); i++) {
				if (amounts[i] > variation[i]) {
					vector<int> newVariation(variation);
					newVariation[i]++;
					vector<vector<int>> newList = solutions(values, amounts, newVariation, price, i);
					if (!newList.empty()) {
						list.insert(list.end(), newList.begin(), newList.end());
						break;
					}
				}
			}
		}
		else if (value == price) {
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
	const vector<vector<int>> getCash(unsigned int cash) {
		////500, 200, 100, 50, 20, 10, 5, 2, 1
		vector<int> values = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };

		vector<int> amounts = { 0, 0, 0, 0, 0, 0, 0, 4, 10 };
		vector<vector<int>> results = solutions(values, amounts, vector<int>(9), cash, 0);
		return results;
	}
};

// 4 корп 3 пов 318, 13:30, четвер, 23 листопада

// TODO make global
class MoneyDisposal : Action {
	friend BanknoteManager;
private:
	const vector<Banknote> _banknotes;
	MoneyDisposal(const vector<Banknote> banknotes) : _banknotes(banknotes) {
		return;
	}
	const string do_toString() const {
		return "TODO toString on MoneyDisposal!!";
	}
public:
	~MoneyDisposal(){}
	const vector<Banknote>& banknotes() const { return _banknotes; };
};
