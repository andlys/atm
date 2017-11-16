#pragma once
#include "Money.h"
//#include "Action.h"
#include <string>
#include <vector>

using namespace std;

class Action;

class Account {
  friend class Bank;
private:
    const string _cardNumber;
    const string _fullName;
    string _phoneNumber;
    Money* _balance;
    string _password;
    //vector<Action> _history;
    bool isValid(const string&, const string&);
    Account(const Account &);
public:
	Account(string, string, unsigned long long);
    Account(string, string, string, unsigned long long);
	~Account();

    // balance modifier
    const Money& balance() const { return *_balance; }

    const string& cardNumber() const { return _cardNumber; }
    const string& fullName() const { return _fullName; }
    const string& phoneNumber() const { return _phoneNumber; }
    //const Money balance(){ return *_balance; }
    //
    // // NOT SECURE AT ALL
    // const string password(){ return _password; }
    // const string password() const { return _password; }
    void updateHistory(const vector<Action>&);
};
