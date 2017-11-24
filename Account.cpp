#include "Account.h"

//TODO delete this constructor
Account::Account(string cardNumber, string password, unsigned long long balance = 0):
                _cardNumber(cardNumber),
                _password(password),
                _balance(new Money(balance)){}

Account::Account(string cardNumber, string name, string password,
    unsigned long long balance, bool blocked):
                _cardNumber(cardNumber),
                _fullName(name),
                _password(password),
                _balance(new Money(balance)),
                _blocked(blocked){}

/*Account::Account(Account const & acc):
                _cardNumber(acc.cardNumber()),
                _password(acc.password()),
                _balance(new Money(acc.balance())){}*/

Account::~Account(){delete _balance;}

bool Account::isValid(const string& cardNum, const string& pass){
    return cardNum == _cardNumber && pass == _password ;
}
