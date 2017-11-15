#include "Transfer.h"

Transfer::Transfer(Account* from, Account* to, Money amount):
                  _from(from),
                  _to(to),
                  _amount(amount){}

Transfer::~Transfer(){}

const string Transfer::toString() const {
    return "";
}
