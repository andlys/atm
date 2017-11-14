#pragma once
#include <vector>
#include <map>
#include "Bank.h"
#include "Action.h"
#include "Account.h"
#include "Transfer.h"
#include <string>
using namespace std;

struct Banknote {
	const unsigned int _nominal;
	const string _code;
	const string _id;
};

class ATM{
private:
    class Session;
    Session* _currentSession;
    class BanknoteManager;
    BanknoteManager* _banknoteManager;
    Bank* _bank;
    const string _address;
public:
    ATM(BanknoteManager&, Bank&);
    ATM(Bank& bank):_currentSession(0),
                _banknoteManager(0),
                _bank(&bank){}
    ~ATM();
    void login(const string&, const string&);
    void logout();
    bool transfer(const string&, const Money&);
    //bool withdrow(const Money&);

};

class ATM::Session {
private:
	vector<Action> _history;
	Account* _currentAccount;
  bool writeToFile();
public:
	Session& pushToHistory(const Action&);
  // TODO make destructor invoking writeToFile();
};

class ATM::BanknoteManager {
private:
	map<int, vector<Banknote>> _available;
	class MoneyDisposal;
  const Money& _m;
public:
	const MoneyDisposal& getCash(unsigned int);
};

// 4 корп 3 пов 318, 13:30, четвер, 23 листопада

// TODO make global
class ATM::BanknoteManager::MoneyDisposal : Action {
	friend BanknoteManager;
private:
	MoneyDisposal();
	//TODO
	const vector<Banknote> _banknotes;
public:
	~MoneyDisposal();
	const vector<Banknote>& banknotes() const;
	//TODO
	virtual const string toString() const;
};
