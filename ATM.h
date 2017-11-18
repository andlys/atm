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
