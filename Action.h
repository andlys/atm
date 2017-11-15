#pragma once
#include <string>

using namespace std;

class Action {
private:
  // _date ??? datetime???
	virtual const string do_toString() const {
		return "default";
	}
public:
	Action() {}
    virtual ~Action() {};
	
    // It seems better to return string, not string&
	const string toString() const {
		return do_toString();
	}
};
