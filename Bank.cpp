#include "Bank.h"
#include <string>
#include <fstream>
#include "lib/json/json.hpp"

Bank* Bank::_self = 0;

Bank::Bank(vector<Account*> accounts):
    _accounts(accounts),
    _commissionWithdrawal(5),
    _commissionTransfer(3),
    _commissionMobileReplenishment(2) {}

bool Bank::updateAccounts() {
	std::ofstream out("accounts_sample.json");
	if (!out.is_open()) {
		cout << "No such file!" << endl;
		return false;
	}
	const vector<Account*> accounts = this->_accounts;
	nlohmann::json j;
	j["accounts"] = {};
	for (int i = 0; i < accounts.size(); ++i) {
		nlohmann::json tmp = {
			{ "balance", accounts[i]->balance().coins() },
			{ "blocked", accounts[i]->isBlocked() },
			{ "cardNumber", accounts[i]->cardNumber() },
			{ "fullName", accounts[i]->fullName() },
			{ "password", accounts[i]->_password },
			{ "phoneNumber", accounts[i]->phoneNumber() }
		};
		j["accounts"].push_back(tmp);
	}
	out << std::setw(2) << j << endl;
	out.close();
	
	return true;
}

Bank::~Bank() { updateAccounts(); }

void Bank::blockAccount(const string& cardNum) {
    Account* acc = getAccount(cardNum);
    if (acc)
        acc->_blocked = true;
    cout << "Bank: account " << cardNum << " is blocked!" << endl; // TODO del
}

const Account& Bank::addToBalance(const Money& amount, Account& target){
    *target._balance += amount;
    return target;
}

const Account& Bank::removeFromBalance(const Money& amount, Account& target){
    *target._balance -= amount;
    return target;
}

vector<Account*> Bank::getUsers() {
	vector<Account*> accounts;

	std::ifstream in("accounts_sample.json");
	if (!in.is_open()) {
		cout << "No such file" << endl;
	}
	else {
		string str((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
		auto s = nlohmann::json::parse(str.c_str());
		auto allAccountsJSONArr = s["accounts"];
		for (int i = 0; i < allAccountsJSONArr.size(); ++i) {
			accounts.push_back(new Account(
				allAccountsJSONArr[i]["cardNumber"],
				allAccountsJSONArr[i]["fullName"],
				allAccountsJSONArr[i]["phoneNumber"],
				allAccountsJSONArr[i]["password"],
				allAccountsJSONArr[i]["balance"],
				allAccountsJSONArr[i]["blocked"]
			));
		}
		in.close();
	}
	return accounts;
}

Account* Bank::getAccount(const string& cardNum, const string& pass){
    for(vector<Account*>::iterator it = _accounts.begin(); it != _accounts.end(); ++it) {
        /* std::cout << *it; ... */
        if ((*it)->isValid(cardNum, pass)) return *it;
    }
    return 0;
}

Account* Bank::getAccount(const string& cardNum){
    for(vector<Account*>::iterator it = _accounts.begin(); it != _accounts.end(); ++it) {
        /* std::cout << *it; ... */
        if ((*it)->cardNumber() == cardNum) return *it;
    }
    return 0;
}

Account* Bank::addAccount(string card, string name, string phone, string pwd,
                          unsigned long long balance, bool blocked){
    // Add new account to vector.
    _accounts.push_back(new Account(card, name, phone, pwd, balance, blocked));
    
    // Get accounts.
    nlohmann::json j;
    std::ifstream in("accounts_sample.json");
    in >> j;
    
    // Create and add new account json object to json data base.
    nlohmann::json newAccount = {
        {"cardNumber", card},
        {"fullName", name},
        {"balance", balance},
        {"password", pwd},
        {"blocked", blocked}
    };
    
    j["accounts"].push_back(newAccount);
    
    // Update history file with new account.
    nlohmann::json h;
    std::ifstream inh("hist_sample.json");
    inh >> h;
    
    nlohmann::json newHist = {
        {"card_id", card},
        {"history", nlohmann::json::array()}
    };
    
    h["histories"].push_back(newHist);
    
    // Write changes to files.
    std::ofstream outA("accounts_sample.json");
    outA << std::setw(2) << j << endl;
    
    std::ofstream outH("hist_sample.json");
    outH << std::setw(2) << h << endl;
    
    return _accounts.back();
}

Bank* Bank::getBank() {
	if (_self == 0)
		_self = new Bank(Bank::getUsers());
	return _self;
}

void Bank::free() {
	delete _self;
};

bool Bank::transfer(Transfer& t) {
    Money commission = t.amount() * _commissionTransfer;
    Money totalWithdraw = commission + t.amount();
    t._success = (*t.from()->_balance >= totalWithdraw);
    if (t._success) {
        *t.to()->_balance += t.amount();
        *t.from()->_balance -= totalWithdraw;
    }
    return t._success;
}

bool Bank::checkIsEnough(const Account &account, const Money &money) {
	return *account._balance >= money;
}

bool Bank::withdraw(Account &account, const Money &money) {
	Money commission = money * _commissionWithdrawal;
	Money totalWithdraw = commission + money;
	if (checkIsEnough(account, totalWithdraw)) {
		*account._balance -= totalWithdraw;
		return true;
	}
	return false;
}

bool Bank::changePIN(Account* acc, const string& oldP, const string& newP) {
	if (acc->_password == oldP && newP.length() == 4) {
		acc->_password = newP;
		return true;
	}
    return false;
}

bool Bank::changePhone(Account *acc, const string& pin, const string& newPhone) {
	if (acc->_password == pin && newPhone.length() == 10) {
		acc->_phoneNumber = newPhone;
		return true;
	}
	return false;
}

bool Bank::replenishPhone(Account *acc, const string &phone, const Money &money) {
	Money commission = money * _commissionMobileReplenishment;
	Money totalWithdraw = commission + money;
	if (checkIsEnough(*acc, totalWithdraw) && phone.length() == 10) {
		*acc->_balance -= totalWithdraw;
		return true;
	}
	return false;
}
