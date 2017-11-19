#include "Transfer.h"

Transfer::Transfer(Account* from, Account* to, const Money& amount):
                  Action(),
                  _from(from),
                  _to(to),
                  _amount(amount){}

Transfer::~Transfer(){}
