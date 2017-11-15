#include "Transfer.h"

Transfer::Transfer(const Account* from, const Account* to, Money amount):
                  _from(from),
                  _to(to),
                  _amount(amount){}

Transfer::~Transfer(){}

const string Transfer::toString() const {
    return "";
}
