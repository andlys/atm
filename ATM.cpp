#include "ATM.h"


ATM::ATM(Bank& bank):
        _currentSession(0),
        _banknoteManager(new BanknoteManager()),
        _bank(&bank){}

ATM::~ATM(){
    delete _currentSession;
    delete _bank;
    delete _banknoteManager;
}

Account* ATM::login(const string& cardNum, const string& pass) {
	Account* acc = _bank->getAccount(cardNum, pass);
	if (acc)
		_currentSession = new Session(acc);
	return acc;
}

Account* ATM::logout() {
	Account* acc = _currentSession->account();
	delete _currentSession;
	_currentSession = 0;
	return acc;
}

Account* ATM::currentAccount() {
	if (_currentSession != 0) return _currentSession->account();
	return 0;
	//return _currentSession->account();
}

// Not secure if session not initiaized.
bool ATM::transfer(const string& to, const Money& amount) {
    Transfer transfer(_currentSession->account(), _bank->getAccount(to), amount);
    Account* a = _currentSession->account();
    return _bank->transfer(transfer);
}

// copying constructor of MoneyDisposal is invoked twice in this method TODO fix
MoneyDisposal ATM::withdraw(unsigned int cash) {
	const MoneyDisposal md = _banknoteManager->getCash(cash);
	//TODO don't work
	//_currentSession->pushToHistory(&md);
	return md;
}
