#pragma once
#include "Account.h"
#include "Transfer.h"
#include "Money.h"
#include <vector>

using namespace std;

class Bank
{
private:
    vector<Account*> _accounts;
    const Account& addToBalance(const Money&, Account&);
    const Account& removeFromBalance(const Money&, Account&);

    // No copying constructor for bank.
    Bank(Bank&);
public:
    Bank(vector<Account*>);
    ~Bank();

    //TODO singleton
    static Bank getBank();
    bool transfer(Transfer&);
    bool withdraw(const Account&, const Money&);
    //bool withdraw(akka-47oont-scrrrraaaa, manidispozal); // TODO
    bool changePIN(const string&, const string&, const string&);

    Account* getAccount(const string&, const string&);

    // Very bad decision
    Account* getAccount(const string&);

    // Delete this. Created for the sake of testing.
    void pseudoAdd(Money amount, Account& acc){
        *acc._balance += amount;
    }
};
