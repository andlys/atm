#pragma once
#include <string>

using namespace std;

class Action {
public:
	Action();
	virtual ~Action();
	virtual const string toString() const = 0;
};

