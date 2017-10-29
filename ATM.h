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

class ATM {

private:
	Bank* _bank;

	// Current Session.
	class Session;
	Session* _session;

	const string _address;
	class BanknoteManager;


public:
  // TODO methods from diagram
};

class ATM::Session {
private:
	vector<Action> _history;
	Account* _currentAccount;
public:
	bool pushToHistory(const Action&);
	bool writeToFile();
};

class ATM::BanknoteManager {
private:
	map<int, vector<Banknote>> _available;
	class BankNoteList;
public:
	const BankNoteList& getCash();
};

class ATM::BanknoteManager::BankNoteList : Action {
	friend BanknoteManager;
private:
	BankNoteList();
	//TODO
	const vector<Banknote> _banknotes;
public:
	~BankNoteList();
	const vector<Banknote>& banknotes() const;
	//TODO
	virtual const string toString() const;
};
