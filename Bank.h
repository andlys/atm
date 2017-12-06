#pragma once
#include "Account.h"
#include "Transfer.h"
#include "Money.h"
#include "MoneyDisposal.h"
#include <vector>

using namespace std;

class Bank
{
private:
	static Bank *_self;
    vector<Account*> _accounts;
    const Account& addToBalance(const Money&, Account&);
    const Account& removeFromBalance(const Money&, Account&);
	static vector<Account*> getUsers();
    // No copying constructor for bank.
    Bank(Bank&);
protected:
	~Bank();
public:
    const unsigned int _commissionWithdrawal;
    const unsigned int _commissionTransfer;
    const unsigned int _commissionMobileReplenishment;

    Bank(vector<Account*>);
    
    static Bank* getBank();
	void free() { delete _self; }
    bool transfer(Transfer&);
	bool checkIsEnough(const Account&, const Money&);
    bool withdraw(Account&, const Money&);
    //bool withdraw(const Account&, const MoneyDisposal&);
    bool changePIN(Account*, const string&, const string&);
	bool changePhone(Account*, const string&, const string&);
	bool phoneReplenishment(Account*, const string&, const Money&);
    void blockAccount(const string&);

    Account* getAccount(const string&, const string&);

    // Very bad decision
    Account* getAccount(const string&);

    // Delete this. Created for the sake of testing.
    void pseudoAdd(Money amount, Account& acc){
        *acc._balance += amount;
    }
};
