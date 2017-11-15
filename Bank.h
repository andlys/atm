#pragma once
#include "Account.h"
//#include "Transfer.h"
#include "Money.h"
#include <vector>

using namespace std;

//class Account;
class Transfer;

class Bank
{
    //friend class Account;
private:
    vector<Account*> _accounts;
    const Account& addToBalance(const Money&, Account&);
    const Account& removeFromBalance(const Money&, Account&);
    
    // No copying constructor for bank.
    Bank(Bank&);
    
public:
    Bank(vector<Account*>);
    ~Bank();
    
    bool transfer(Transfer&);
    bool withdraw(const Account&, const Money&);
    
    Account* getAccount(const string&, const string&);
    
    // Delete this. Created for the sake of testing.
    void pseudoAdd(Money amount, Account& acc){
        *acc._balance = *acc._balance + amount;
    }
};
