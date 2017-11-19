#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Bank.h"
#include "Action.h"
#include "Account.h"
#include "Transfer.h"
#include <string>
#include "Banknote.h"
#include "BanknoteManager.h"

using namespace std;

class ATM {
private:
	class Session {
	private:
		vector<const Action*> _history;
		Account* _account;
		bool writeToFile() {
			for (vector<const Action*>::iterator it = _history.begin(); it != _history.end(); ++it) {
				// TODO send to file
				cout << (*it)->datetimeString() << " - " << (*it)->toString() << endl;
			}
			return false; // TODO
		}
	public:
		Session(Account* acc) : _account(acc) {}
		~Session() {
			writeToFile();
			delete _account;
			return;
		};

		Account* account() const { return _account; }
		Session& pushToHistory(const Action* action) {
			_history.push_back(action);
			return *this;
		}
	};
    Session* _currentSession;
    //class BanknoteManager;
    BanknoteManager* _banknoteManager;
    Bank* _bank;
    const string _address;
    friend void test_session(void); // TODO comment
public:
    ATM(Bank&);
    ~ATM();
	Account* login(const string&, const string&);
	Account* logout();
	Account* currentAccount();
    bool transfer(const string&, const Money&);
	MoneyDisposal withdraw(unsigned int);
};
