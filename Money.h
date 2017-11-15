#pragma once
class Money {
private:
	unsigned long long _coins;

public:
	Money(const unsigned long long);
    // MAKE COPYING CONSTRUCTOR!
    // Money(const Money&)
	~Money();

	const Money operator+(const Money&);
	const Money operator-(const Money&);
	const Money operator*(const Money&);
	const Money operator/(const Money&);
    bool operator>=(const Money&);
	operator double();
    
    const unsigned long long& coins();
    const unsigned long long& coins() const;

};
