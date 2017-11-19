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
    Bank* const _bank;
    const string _address;
    friend void test_session(void); // TODO comment
public:
    ATM(Bank* const);
    ~ATM();
	Account* login(const string&, const string&);
	Account* logout();
	Account* currentAccount();
    bool transfer(const string&, const Money&);
	MoneyDisposal withdraw(unsigned int);
};
