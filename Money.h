#pragma once
class Money {
private:
	unsigned long long _coins;

public:
	Money(const double);
	~Money();

	Money& operator+(const Money&);
	Money& operator-(const Money&);
	Money& operator*(const Money&);
	Money& operator/(const Money&);
  bool   operator>=(const Money&);
	operator double();
};
