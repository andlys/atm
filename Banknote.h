#pragma once
#include <string>

using namespace std;

struct Banknote {
	const unsigned int _nominal;
	const string _code;
	const string _id;
};

ostream& operator<<(ostream &os, const Banknote &b) {
	os << "Nominal: " << b._nominal << endl;
	os << "Code: " << b._code << endl;
	os << "Id: " << b._id << endl;
	return os;
}