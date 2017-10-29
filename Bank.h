#pragma once
#include "Account.h"
#include "Transfer.h"
#include "Money.h"
class Bank
{
private:
  <vector> _accounts;
  bool addToBalance(const Money&, Account&);
  bool removeFromBalance(const Money&, Account&);
public:
	Bank();
	~Bank();
  const Transfer& transfer(Transfer&);
  bool withdraw(const Account&, const Money&); // TODO check return type
};
