#pragma once
#include <string>
#include <iostream>
#include "lib/fmt-4.0.0/fmt/format.h"

using std::string;
using std::ostream;
using std::endl;

struct Banknote {
	const unsigned int _nominal;
	const string _code;
	const string _id;
    const string toString() const {
        return fmt::format("{0} ({1}) {2}", _nominal, _code, _id);
    }
};

inline ostream& operator<<(ostream &os, const Banknote &b) {
	os << "Nominal: " << b._nominal << endl;
	os << "Code: " << b._code << endl;
	os << "Id: " << b._id << endl;
	return os;
}
