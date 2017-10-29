#pragma once
#include <string>

using namespace std;

class Action {
private:
  // _date ??? datetime???
public:
	Action();
	virtual ~Action();
	virtual const string& toString() const = 0;
};
