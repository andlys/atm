#include "Money.h"

Money::Money(const unsigned long long balance):_coins(balance){}

Money::~Money(){}

Money::operator double() const { return _coins/100.0; }

//const unsigned long long& Money::coins(){ return _coins; } // TODO delete this line, see .h file
const unsigned long long& Money::coins() const{ return _coins; }

Money& Money::operator+=(const Money& m){
    _coins += m.coins();
    return *this;
}

Money& Money::operator-=(const Money& m){
    _coins -= m.coins();
    return *this;
}

const Money operator*(const Money& m, const unsigned int percentage) {
    return Money( (m.coins() * percentage) / 100 );
}

bool operator>=(const Money& a, const Money& b) {
    return a.coins() >= b.coins();
}

const Money operator+(const Money& a, const Money& b){
    return Money(a.coins() + b.coins());
}

const Money operator-(const Money& a, const Money& b){
    return Money(a.coins() - b.coins());
}
