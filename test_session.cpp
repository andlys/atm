#include <iostream>
#include "ATM.h"
#include "Account.h"
#include "Action.h"
#include "Money.h"
#include "Transfer.h"

using namespace std;

void test_session(void);

int main() {
    test_session();
    return 0;
}

void test_session(void) {
    Account acc("777", "Paul Graham", "0", 500);
    Account acc2("888", "Nikolas Taleb", "0", 100);
    Account* acc5 = new Account("777", "Paul Graham", "0", 500);
    Account* acc6 = new Account("888", "Nikolas Taleb", "0", 100);
    {
        ATM::Session s(new Account("333", "Umberto Eko", "0", 500));
        s.pushToHistory(new Action("login"));
        s.pushToHistory(new Transfer(acc5, acc6, Money(30)));
        s.pushToHistory(new Action("changed PIN"));
        s.pushToHistory(new Action("logout"));
    }
    {
        // cout << Transfer(acc5, acc6, Money(30)).toString() << endl;
        // Action* a = new Transfer(acc5, acc6, Money(30));
        // Transfer t(acc5, acc6, Money(30));
        // cout << t.toString() << endl;
        // Action action = t;
        // cout << action.toString() << endl;
        // cout << (*a).toString() << endl;
        // delete a;
    }
    delete acc5;
    delete acc6;
    //cout << Action().toString() << endl;
}
