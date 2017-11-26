#pragma once
#include "Account.h"
#include "Action.h"

using std::string;

class AccountAction : public Action {
private:
	const string do_toString() const;
	//Account* _acc;
	string _content;
public:
	AccountAction(const string& content) : _content(content) {};
	~AccountAction();
};

