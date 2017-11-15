#pragma once
#include <string>

using namespace std;

class Action {
private:
  // _date ??? datetime???
public:
	//Action();
    virtual ~Action() {};
	
    // It seems better to return string, not string&
    virtual const string toString() const = 0;
};
