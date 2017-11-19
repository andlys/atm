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
    class Session;
    Session* _currentSession;
    //class BanknoteManager;
    BanknoteManager* _banknoteManager;
    //Bank* const _bank;
    Bank& _bank;
    const string _address;
    friend void test_session(void); // TODO comment
public:
    //ATM(Bank* const);
    ATM(Bank&);
    ~ATM();
	Account* login(const string&, const string&);
	Account* logout();
	Account* currentAccount();
    bool transfer(const string&, const Money&);
	MoneyDisposal withdraw(unsigned int);
    // it is safe since Bank is const
    const Bank& bank() { return _bank; }
    // it is safe since Account is const
    const Account* getAccount(const string& cardId) {
        return _bank.getAccount(cardId);
    }
};
