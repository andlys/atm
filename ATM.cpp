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
    const Account* _currentAccount;
public:
    Session(const Account* acc): _currentAccount(acc){}
    ~Session(){};
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
    Account* acc;
    if(acc = _bank->getAccount(cardNum, pass))
        _currentSession = new Session(acc);
    
}
