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

Bank::~Bank(){}

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

Bank* Bank::getBank() {
	Bank::getUsers();
	if (_self == 0)
		_self = new Bank(Bank::getUsers());
	return _self;
}

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

bool Bank::phoneReplenishment(Account *acc, const string &phone, const Money &money) {
	Money commission = money * _commissionMobileReplenishment;
	Money totalWithdraw = commission + money;
	if (checkIsEnough(*acc, totalWithdraw)) {
		*acc->_balance -= totalWithdraw;
		return true;
	}
	return false;
}
