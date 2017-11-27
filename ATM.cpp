#include "ATM.h"

class ATM::Session {
private:
    vector<const Action*> _history;
    Account* _account;
    bool writeToFile() {
        for (vector<const Action*>::iterator it = _history.begin(); it != _history.end(); ++it) {
            // TODO send to file
            cout << (*it)->datetimeString() << " - " << (*it)->toString() << endl;
        }
        return false; // TODO
    }
public:
    Session(Account* acc) : _account(acc) {}
    ~Session() {
        writeToFile();
        delete _account;
        return;
    };

    Account* account() const { return _account; }
    Session& pushToHistory(const Action* action) {
        _history.push_back(action);
        return *this;
    }
};

ATM::ATM(Bank& bank):
        _currentSession(0),
        _banknoteManager(new BanknoteManager()),
        _bank(bank),
        _attemptsLeft(3),
        _lastAttemptedCardNumber(""){}

ATM::~ATM(){
    delete _currentSession;
    //delete _bank;
    delete _banknoteManager;
}

Account* ATM::login(const string& cardNum, const string& pass) {
    if (_currentSession)
        logout();
    Account* acc = 0;
    if (_lastAttemptedCardNumber != cardNum) {
        _attemptsLeft = 3;
        _lastAttemptedCardNumber = cardNum;
    }
    if (_attemptsLeft) {
        _attemptsLeft--;
    	acc = _bank.getAccount(cardNum, pass);
    	if (acc)
    		_currentSession = new Session(acc);
        else if (_attemptsLeft == 0)
            _bank.blockAccount(cardNum);
    }
	return acc;
}

Account* ATM::logout() {
	Account* acc = 0;
    if (_currentSession) {
        acc = _currentSession->account();
        delete _currentSession;
	    _currentSession = 0;
        _attemptsLeft = 3;
        _lastAttemptedCardNumber = "";
    }
	return acc;
}

Account* ATM::currentAccount() {
	if (_currentSession)
        return _currentSession->account();
	return 0;
}

// Not secure if session not initiaized.
bool ATM::transfer(const string& to, const Money& amount) {
    Transfer transfer(_currentSession->account(), _bank.getAccount(to), amount);
    _currentSession->pushToHistory(&transfer); // TODO check
    return _bank.transfer(transfer);
}

// copying constructor of MoneyDisposal is invoked twice in this method TODO fix
const MoneyDisposal ATM::withdraw(unsigned int cash) {
	Money money(cash * 100);
	Money commission = money * _bank._commissionWithdrawal;
	Money totalWithdraw = commission + money;
	if (!_bank.checkIsEnough(*currentAccount(), totalWithdraw)) {
		const MoneyDisposal md = _banknoteManager->getCash(0);
		return md;
	}
	
	const MoneyDisposal md = _banknoteManager->getCash(cash);
	_currentSession->pushToHistory(&md);
	if (md.isSuccess()) {
		_bank.withdraw(*currentAccount(), Money(cash * 100));
	}
	return md;
}

bool ATM::changePIN(const string & oldP, const string & newP) {
	if (_bank.changePIN(currentAccount(), oldP, newP)) {
		_currentSession->pushToHistory(new AccountAction("Account with card number: " + currentAccount()->cardNumber() + " change PIN"));
		return true;
	}
	return false;
}

bool ATM::changePhoneNumber(const string& oldPhone, const string& newPhone) {
	if (_bank.changePhone(currentAccount(), oldPhone, newPhone)) {
		_currentSession->pushToHistory(new AccountAction("Account with card number: " + currentAccount()->cardNumber() + " change Phone from: " + oldPhone + " to: " + newPhone));
		return true;
	}
	return false;
}

bool ATM::phoneReplenishment(const string &phone, const Money &money) {
	Money commission = money * _bank._commissionMobileReplenishment;
	Money totalWithdraw = commission + money;
	if (!_bank.checkIsEnough(*currentAccount(), totalWithdraw)) {
		return false;
	}
	if (_bank.phoneReplenishment(currentAccount(), phone, money)) {
		string replenishedMoney = std::to_string((double)money);
		_currentSession->pushToHistory(new AccountAction("Account with card number: " + currentAccount()->cardNumber() + " replenished the phone: " + phone + " on sum: " + replenishedMoney));
		return true;
	}
	return false;
}
