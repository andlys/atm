#pragma once
struct Money {
private:
	unsigned long long _coins;

public:
  // accepts number of coins
	Money(const unsigned long long);
    // MAKE COPYING CONSTRUCTOR!
    // Money(const Money&)
	~Money();

  // returns real quantity of money converted from coins
	explicit operator double() const;

  // const unsigned long long& coins(); // TODO delete this line, the method below already can handle this
  const unsigned long long& coins() const;
  Money& operator+=(const Money&);
  Money& operator-=(const Money&);
};

const Money operator+(const Money&, const Money&);
const Money operator-(const Money&, const Money&);
// percentage - number of percents, e.g.: 50% = 50; 103% = 103 and so on
const Money operator*(const Money& m, const unsigned int percentage);
// const Money operator/(const Money&, const Money&); // TODO delete this line; the operator is useless
bool operator>=(const Money&, const Money&);
