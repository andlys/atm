#include "ATM.h"
#include <fstream>
#include "lib/json/json.hpp"

class ATM::Session {
private:
    vector<const Action*> _history;
    Account* _account;
    bool writeToFile() {
        //nlohmann::json hist [_history.size()];
        std::ofstream out("test.json");
        auto hist = nlohmann::json::array();
        /*nlohmann::json hJson = {
         {"card_id", _account->cardNumber()},
         {"history", nlohmann::json::array()}
         };*/
        cout << _history.size() << endl;
        for (vector<const Action*>::iterator it = _history.begin(); it != _history.end(); ++it) {
            nlohmann::json j = {
                {"datetime","13"},
                {"action", "action"}
            };
            //hist[i] = j;
            hist.push_back(j);
            out << "f" << endl;
            out << std::setw(2) << j << endl;
            
        }
        return false;
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
    	if (acc) {
    		_currentSession = new Session(acc);
            _currentSession->pushToHistory(new AccountAction("Signed in"));
        }
        else if (_attemptsLeft == 0)
            _bank.blockAccount(cardNum);
    }
	return acc;
}

Account* ATM::logout() {
	Account* acc = 0;
    if (_currentSession) {
        acc = _currentSession->account();
        _currentSession->pushToHistory(new AccountAction("Logged out"));
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
    Transfer* transfer = new Transfer(_currentSession->account(), _bank.getAccount(to), amount);
    _currentSession->pushToHistory(transfer);
    return _bank.transfer(*transfer);
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
	if (md.isSuccess()) {
		_bank.withdraw(*currentAccount(), Money(cash * 100));
        //_currentSession->pushToHistory(&md);
        _currentSession->pushToHistory(new AccountAction(fmt::format(
            "Withdrawn {} uah", cash))); // TODO refactor and change to md
	}
	return md;
}

bool ATM::changePIN(const string & oldP, const string & newP) {
	if (_bank.changePIN(currentAccount(), oldP, newP)) {
		_currentSession->pushToHistory(new AccountAction("PIN changed"));
		return true;
	}
	return false;
}

bool ATM::changePhoneNumber(const string& oldPhone, const string& newPhone) {
	if (_bank.changePhone(currentAccount(), oldPhone, newPhone)) {
        Action* action = new AccountAction(fmt::format(
            "Phone number changed from {} to {}", oldPhone, newPhone));
        _currentSession->pushToHistory(action);
		return true;
	}
	return false;
}

bool ATM::phoneReplenishment(const string &phone, const Money &money) {
	Money commission = money * _bank._commissionMobileReplenishment;
	Money totalWithdraw = commission + money;
	if (_bank.checkIsEnough(*currentAccount(), totalWithdraw) &&
        _bank.phoneReplenishment(currentAccount(), phone, money)) {
		_currentSession->pushToHistory(new AccountAction(fmt::format(
            "Replenished phone number {} with {} {}", phone,
            double(money), money.code())));
		return true;
	}
	return false;
}
