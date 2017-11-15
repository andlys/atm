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
public:
	Account(string, string, double);
    Account(Account const &);
	~Account();
    
    // balance modifier
    const Money& balance(){ return *_balance; }
    const Money& balance() const { return *_balance; }
    
    const string cardNumber(){ return _cardNumber; }
    const string cardNumber() const { return _cardNumber; }
    const string fullName(){ return _fullName; }
    const string fullName() const { return _fullName; }
    const string phoneNumber(){ return _phoneNumber; }
    const string phoneNumber() const { return _phoneNumber; }
    //const Money balance(){ return *_balance; }
    
    // NOT SECURE AT ALL
    const string password(){ return _password; }
    const string password() const { return _password; }
    
    bool isValid(const string&, const string&);
    
    void updateHistory(const vector<Action>&);
	bool changePIN(const string, const string);
};
