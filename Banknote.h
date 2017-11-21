#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::endl;

struct Banknote {
	const unsigned int _nominal;
	const string _code;
	const string _id;
};

inline ostream& operator<<(ostream &os, const Banknote &b) {
	os << "Nominal: " << b._nominal << endl;
	os << "Code: " << b._code << endl;
	os << "Id: " << b._id << endl;
	return os;
}
