#pragma once
struct Money {
private:
	unsigned long long _coins;

public:
	Money(const unsigned long long);
    // MAKE COPYING CONSTRUCTOR!
    // Money(const Money&)
	~Money();

	operator double();

  const unsigned long long& coins();
  const unsigned long long& coins() const;

};

const Money operator+(const Money&, const Money&);
const Money operator-(const Money&, const Money&);
const Money operator*(const Money&, const Money&);
const Money operator/(const Money&, const Money&);
bool operator>=(const Money&, const Money&);
