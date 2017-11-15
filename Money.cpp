#include "Money.h"

Money::Money(const unsigned long long balance):_coins(balance){}

Money::~Money(){}

Money::operator double(){ return double(_coins*100); }

const unsigned long long& Money::coins(){ return _coins; }
const unsigned long long& Money::coins() const{ return _coins; }

const Money operator+(const Money& a, const Money& b){
    return Money(a.coins() + b.coins());
}

const Money operator-(const Money& a, const Money& b){
    return Money(a.coins() - b.coins());
}
