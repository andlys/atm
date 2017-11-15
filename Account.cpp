#include "Account.h"

Account::Account(string cardNumber, string password, double balance = 0):
                _cardNumber(cardNumber),
                _password(password),
                _balance(new Money(balance)){}

Account::Account(Account const & acc):
                _cardNumber(acc.cardNumber()),
                _password(acc.password()),
                _balance(new Money(acc.balance())){}

Account::~Account(){delete _balance;}

bool Account::isValid(const string& cardNum, const string& pass){
    return cardNum == _cardNumber && pass == _password ;
}
