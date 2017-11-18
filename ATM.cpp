//
//  ATM.cpp
//  Bank
//
//  Created by Denys Melnychenko on 11/13/17.
//  Copyright © 2017 Denys Melnychenko. All rights reserved.
//

#include "ATM.h"

class ATM::Session{
private:
    vector<const Action*> _history;
    Account* _account;
    bool writeToFile() {
        for (vector<const Action*>::iterator it = _history.begin(); it != _history.end(); ++it) {
            // TODO send to file
            cout << (*it)->datetimeString() << " - " << (*it)->toString() << endl;
        }
        return false; // TODO
    }
public:
    Session(Account* acc): _account(acc){}
    ~Session() {
        writeToFile();
        for (vector<const Action*>::iterator it = _history.begin(); it != _history.end(); ++it) {
            delete *it; // TODO remove once we implement smart ptr
        }
        delete _account;
        return;
    }
    bool setAccount(const Account& account) {
        if (_account != 0) return false;
        //TODO need copy constuctor
        //_currentAccount(account);
        return true;
    }
    Session& pushToHistory(const Action* action) {
        _history.push_back(action);
        return *this;
    }
    
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

Account* ATM::login(const string& cardNum, const string& pass){
    Account* acc = _bank->getAccount(cardNum, pass);
    if(acc)
        _currentSession = new Session(acc);
    return acc;
}

Account* ATM::logout(){
    Account* acc = _currentSession->account();
    delete _currentSession;
    _currentSession = 0;
    return acc;
}

Account* ATM::currentAccount(){
    if(_currentSession != 0) return _currentSession->account();
    return 0;
    //return _currentSession->account();
}

// Not secure if session not initiaized.
bool ATM::transfer(const string& to, const Money& amount){
    if(_currentSession != 0){
        Transfer transfer(currentAccount(), _bank->getAccount(to), amount);
        return _bank->transfer(transfer);
    }
    return false;
}






