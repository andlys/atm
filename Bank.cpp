#include "Bank.h"

Bank::Bank(vector<Account*> accounts):
    _accounts(accounts),
    _commissionWithdrawal(5),
    _commissionTransfer(3),
    _commissionMobileReplenishment(2) {}

Bank::~Bank(){}

void Bank::blockAccount(const string& cardNum) {
    Account* acc = getAccount(cardNum);
    if (acc)
        acc->_blocked = true;
    cout << "Bank: account " << cardNum << " is blocked!" << endl; // TODO del
}

const Account& Bank::addToBalance(const Money& amount, Account& target){
    *target._balance += amount;
    return target;
}

const Account& Bank::removeFromBalance(const Money& amount, Account& target){
    *target._balance -= amount;
    return target;
}

Account* Bank::getAccount(const string& cardNum, const string& pass){
    for(vector<Account*>::iterator it = _accounts.begin(); it != _accounts.end(); ++it) {
        /* std::cout << *it; ... */
        if ((*it)->isValid(cardNum, pass)) return *it;
    }
    return 0;
}

Account* Bank::getAccount(const string& cardNum){
    for(vector<Account*>::iterator it = _accounts.begin(); it != _accounts.end(); ++it) {
        /* std::cout << *it; ... */
        if ((*it)->cardNumber() == cardNum) return *it;
    }
    return 0;
}

bool Bank::transfer(Transfer& t){
    Money commission = t.amount() * _commissionTransfer;
    Money totalWithdraw = commission + t.amount();
    t._success = (*t.from()->_balance >= totalWithdraw);
    if (t._success) {
        *t.to()->_balance += t.amount();
        *t.from()->_balance -= totalWithdraw;
    }
    return t._success;
}

bool Bank::changePIN(Account* acc, const string& oldP, const string& newP){
    return 0;
}
