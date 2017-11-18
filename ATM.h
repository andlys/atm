//
//  ATM.h
//  Bank
//
//  Created by Denys Melnychenko on 11/13/17.
//  Copyright © 2017 Denys Melnychenko. All rights reserved.
//

#ifndef ATM_h
#define ATM_h

#include <stdio.h>
#include <iostream>
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
    // Just for testing.
    ATM(Bank& bank):_currentSession(0),
                    _banknoteManager(0),
                    _bank(&bank){}
    ~ATM();
    Account* login(const string&, const string&);
    Account* logout();
    
    Account* currentAccount();
    
    bool transfer(const string&, const Money&);
    bool withdrow(const Money&);
    
};

#endif /* ATM_h */

