#pragma once
#include "Money.h"
//#include "Action.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Action;

class Account {
  friend class Bank;
private:
    const string _cardNumber;
    const string _fullName;
    string _phoneNumber;
    Money* _balance;
    string _password;
    bool _blocked;
    //vector<Action> _history; // TODO
    bool isValid(const string&, const string&);
    Account(const Account &);
public:
	Account(string, string, unsigned long long); // TODO delete
    Account(string card, string name, string pwd,
        unsigned long long balance = 0, bool blocked = false);
	~Account();

    // balance selector
    const Money& balance() const { return *_balance; }
    const string& cardNumber() const { return _cardNumber; }
    const string& fullName() const { return _fullName; }
    const string& phoneNumber() const { return _phoneNumber; }
    void updateHistory(const vector<Action>&);
    bool isBlocked() const { return _blocked; }
};
