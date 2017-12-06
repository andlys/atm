#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Bank.h"
#include "Action.h"
#include "Account.h"
#include "AccountAction.h"
#include "Transfer.h"
#include <string>
#include "Banknote.h"
#include "BanknoteManager.h"

using namespace std;

class ATM {
private:
    class Session;
    Session* _currentSession;
    //class BanknoteManager;
    BanknoteManager* _banknoteManager;
    //Bank* const _bank;
    Bank& _bank;
    const string _address;
    unsigned int _attemptsLeft;
    string _lastAttemptedCardNumber;
    friend void test_session(void); // TODO comment
public:
    //ATM(Bank* const);
    ATM(Bank&);
    ~ATM();
	Account* login(const string&, const string&);
    // returns number of attempts left, starting from tree (before first call)
	unsigned int loginAttemptsLeft() { return _attemptsLeft; }
    bool isloggedIn() { return _currentSession != 0; }
	Account* logout();
	Account* currentAccount();
    bool transfer(const string&, const Money&);
	const MoneyDisposal withdraw(unsigned int);
	bool changePIN(const string&, const string&);
	bool changePhoneNumber(const string&, const string&);
	bool replenishPhone(const string&, const Money&);
    vector<string> getAllHistory();
    // it is safe since Bank is const
    const Bank& bank() { return _bank; }
    // it is safe since Account is const
    const Account* getAccount(const string& cardId) {
        return _bank.getAccount(cardId);
    }
	const vector<int> availableNominals() const;
};
