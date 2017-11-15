#include "Money.h"

Money::Money(const unsigned long long balance):_coins(balance){}

Money::~Money(){}

Money::operator double(){ return double(_coins*100); }

const unsigned long long& Money::coins(){ return _coins; }
const unsigned long long& Money::coins() const{ return _coins; }

const Money Money::operator+(const Money& amount){
    return Money(this->coins()+amount.coins());
}

const Money Money::operator-(const Money& amount){
    return Money(this->coins()-amount.coins());
}
