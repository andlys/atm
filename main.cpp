//
//  main.cpp
//  Bank
//
//  Created by Denys Melnychenko on 11/8/17.
//  Copyright © 2017 Denys Melnychenko. All rights reserved.
//

#include <iostream>
#include "Bank.h"
#include "ATM.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /*const Account& acc1 = Account("1", "qwerty", 13);
    const Account& acc2 = Account("2", "qwerty", 13);
    const Account& acc3 = Account("3", "qwerty", 13);*/
    
    /*Account acc1("1", "qwerty", 13);
    Account acc2("2", "qwerty", 13);
    Account acc3("3", "qwerty", 13);*/
    
    /*const Account* acc1 = new Account("1", "qwerty", 13);
    const Account* acc2 = new Account("2", "qwerty", 13);
    const Account* acc3 = new Account("3", "qwerty", 13);*/
    
    vector<Account*> accounts;
    accounts.push_back(new Account("1", "qwerty", 13));
    accounts.push_back(new Account("2", "qwerty", 13));
    accounts.push_back(new Account("3", "qwerty", 13));
    
    /*const Account* acc1 = new Account("1", "qwerty", 13);
    const Account* acc2 = new Account("2", "qwerty", 13);
    const Account* acc3 = new Account("3", "qwerty", 13);
    
    vector<Account> accounts;
    accounts.push_back(*acc1);
    accounts.push_back(*acc2);
    accounts.push_back(*acc3);*/
    
    Bank bank(accounts);
    
    ATM atm(bank);
    
    atm.login("1", "qwerty");
    
    bank.pseudoAdd(1234, *accounts[0]);
    
    return 0;
}
