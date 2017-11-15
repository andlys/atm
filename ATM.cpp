//
//  ATM.cpp
//  Bank
//
//  Created by Denys Melnychenko on 11/13/17.
//  Copyright © 2017 Denys Melnychenko. All rights reserved.
//

#include "ATM.hpp"

class ATM::Session{
private:
    //stack history
    Account* _account;
public:
    Session(Account* acc): _account(acc){}
    ~Session(){};
    
    Account* account() const { return _account; }
};

ATM::ATM(BanknoteManager& bm, Bank& bank):
        _currentSession(0),
        _banknoteManager(&bm),
        _bank(&bank){}

ATM::~ATM(){
    delete _currentSession;
    //delete _bank;
    //delete _banknoteManager;
}

void ATM::login(const string& cardNum, const string& pass){
    Account* acc = _bank->getAccount(cardNum, pass);
    if(acc)
        _currentSession = new Session(acc);
    
}

Account* ATM::currentAccount(){
    if(_currentSession != 0) return _currentSession->account();
    return 0;
    //return _currentSession->account();
}

// Not secure if session not initiaized.
bool ATM::transfer(const string& to, const Money& amount){
    Transfer transfer(currentAccount(), _bank->getAccount(to), amount);
    Account* a = currentAccount();
    return _bank->transfer(transfer);
}






