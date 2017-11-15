#include "Bank.h"

Bank::Bank(vector<Account*> accounts): _accounts(accounts){}

Bank::~Bank(){}

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
    Money commission = t.amount() * 3; // commission is 3 %
    // maybe we should store total amount of commissions somewhere in bank?
    Money totalWithdraw = commission + t.amount();
    if (t._success = (*t.from()->_balance >= totalWithdraw)) {
        *t.to()->_balance += t.amount();
        *t.from()->_balance -= totalWithdraw;
    }
    return t._success;
}
