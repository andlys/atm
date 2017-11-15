//
//  ATM.hpp
//  Bank
//
//  Created by Denys Melnychenko on 11/13/17.
//  Copyright © 2017 Denys Melnychenko. All rights reserved.
//

#ifndef ATM_hpp
#define ATM_hpp

#include <stdio.h>
#include "Bank.h"

class ATM{
private:
    class Session;
    Session* _currentSession;
    class BanknoteManager;
    BanknoteManager* _banknoteManager;
    Bank* _bank;
public:
    ATM(BanknoteManager&, Bank&);
    ATM(Bank& bank):_currentSession(0),
                _banknoteManager(0),
                _bank(&bank){}
    ~ATM();
    void login(const string&, const string&);
    void logout();
    bool transfer(const string&, const Money&);
    
};

#endif /* ATM_hpp */
