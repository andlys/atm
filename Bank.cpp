#include "Bank.h"

Bank::Bank(vector<Account*> accounts): _accounts(accounts){}

Bank::~Bank(){}

const Account& Bank::addToBalance(const Money& amount, Account& target){
    *target._balance = *target._balance + amount;
    return target;
}

const Account& Bank::removeFromBalance(const Money& amount, Account& target){
    *target._balance = *target._balance - amount;
    return target;
}

Account* Bank::getAccount(const string& cardNum, const string& pass){
    for(vector<Account*>::iterator it = _accounts.begin(); it != _accounts.end(); ++it) {
        /* std::cout << *it; ... */
        if ((*it)->isValid(cardNum, pass)) return *it;
    }
    return 0;
}
