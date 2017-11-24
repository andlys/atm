#include <iostream>
#include <string>
#include "lib/fmt-4.0.0/fmt/format.h"
#include "lib/fmt-4.0.0/fmt/printf.h"
#include "ATM.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

const string menu("Choose an action to perform:\n"
                  "1 - print balance\n"
                  "2 - withdraw money\n"
                  "3 - transfer money\n"
                  "4 - change phone number\n"
                  "5 - change PIN\n"
                  "6 - exit and release card\n"
                  // TODO replenish mobile phone
                  );
const string greetingPattern("Login successful\n\n"
                             "Greetings, dear %s!\n\n");

// TODO make it singleton?
class DynamicModel {
private:
    ATM* const _atm;
    bool validateLogin(void);
    bool validatePINInput(const string&);
    void processMenuInteraction(void);
    void menuDoPrintBalance(void);
    void menuDoWithdraw(void);
    void menuDoTransfer(void);
    void menuDoChangePhone(void);
    void menuDoChangePIN(void);
    void menuDoExit(void);
    void menuDoIncorrectOption(void);
    void doPressEnterToContinue(void);
public:
    DynamicModel(ATM* const atm): _atm(atm) {}
    void initialize(void);
    ~DynamicModel() { delete _atm; }
};

void DynamicModel::doPressEnterToContinue() {
    cin.clear();
    cin.ignore(10000, '\n');
    string tmp;
    cout << "Press Enter to continue" << endl;
    std::getline(cin, tmp);
}

void DynamicModel::initialize() {
    // menuDoTransfer();
    // while (true) {
        if (validateLogin()) {
            processMenuInteraction();
        }
        // doPressEnterToContinue();
    // }
}

bool DynamicModel::validateLogin() {
    cout << "Hello! Please, sign in." << endl;
    cout << "Input card id: ";
    string card_id;
    cin >> card_id;
    const Account* acc = _atm->getAccount(card_id);
    if (acc) {
        if (acc->isBlocked()) {
            cout << "Failure: can't proceed since your account is blocked. "
                    "Contact the service to resolve the issue." << endl;
        } else
            return validatePINInput(card_id);
    } else {
        cout << "Failure: can't proceed since card id is incorrect" << endl;
    }
    return false;
}

bool DynamicModel::validatePINInput(const string& card_id) {
    while (true) {
        string pin;
        cout << "Input PIN: ";
        cin >> pin; // TODO hide user input
        if (_atm->login(card_id, pin)) {
            return true;
        } else {
            if (_atm->loginAttemptsLeft()) {
                fmt::printf("Incorrect PIN, %s attemps left\n", _atm->loginAttemptsLeft());
            } else {
                cout << "Failure: you have exceeded three attempts! Card is blocked!" << endl;
                return false;
            }
        }
    }
}

void DynamicModel::processMenuInteraction() {
    fmt::printf(greetingPattern, _atm->currentAccount()->fullName());
    cout << menu;
    bool exit = false;
    while (!exit) {
        cout << "Please, select operation by number: ";
        unsigned int menuOption;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> menuOption;
        switch (menuOption) {
            case  1: menuDoPrintBalance(); break;
            case  2: menuDoWithdraw(); break;
            case  3: menuDoTransfer(); break;
            case  4: menuDoChangePhone(); break;
            case  5: menuDoChangePIN(); break;
            case  6: menuDoExit(); exit = true; break;
            default: menuDoIncorrectOption(); break;
        }
    }
}

void DynamicModel::menuDoPrintBalance() {
    cout << "(printing balance...)" << endl;
    // fmt::printf("Your balance is %.2f %s",
    //     double( atm->currentAccount()->balance() ),
    //     atm->currentAccount()->balance()->code());
}

void DynamicModel::menuDoWithdraw() {
    cout << "(withdrawing money...)" << endl;
    // check if atm has at least some money???
    cout << "Available nominals: 5, 10, 20, 50, 100, TODO" << endl; // concat vector to string
    cout << "Input amount of money to withdraw: ";
    unsigned int amount;
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> amount;
    cout << _atm->withdraw(amount) << endl;
    // if ( !vector.empty() ) {
    //     cout << "Success" << endl;
    // } else {
    //     cout << "Failure: unable to give you this specific amount of money"
    //          << "Please, try another amount"<< endl;
    // }
    doPressEnterToContinue();
}

void DynamicModel::menuDoTransfer() {
    cout << "(transfering money...)" << endl;
    cout << "Input recipient's card id" << endl;
    string recipientCardId;
    cin >> recipientCardId;
    double amount;
    while (true) {
        cout << "Input amount of money to transfer (floating point, precision up to 0.01): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> amount;
        if ( (amount < 0) || Money(amount * 100).coins() == 0 )
            cout << "Invalid amount!" << endl;
        else
            break;
    }
    Money money(amount * 100); // converting to coins
    // cout << double(money) << " is ok" << endl; // TODO delete
    const Money& total = money * (100 + _atm->bank()._commissionTransfer);
    fmt::printf("Transfer plus commission of %d %c costs %.2f %s\n",
        _atm->bank()._commissionTransfer, '%',
        double(total), total.code());
    if (_atm->currentAccount()->balance() >= total) {
        const Account* recipient = _atm->getAccount(recipientCardId);
        // TODO check if recipient is not blocked!
        if (recipient) {
            fmt::printf("Are you sure to make a transer of %.2f %s to #%s (%s)",
                double(money), money.code(),
                recipient->cardNumber(), recipient->fullName());
            while (true) {
                cout << "Enter y/n: ";
                string answer;
                cin >> answer;
                if (answer == "y" || answer == "Y") {
                    if ( _atm->transfer(recipientCardId, money) )
                        cout << "Success!" << endl;
                    else
                        cout << "Failure: request was declined by ATM" << endl;
                    break;
                } else if (answer == "n" || answer == "N") {
                    cout << "Operation was discarded!" << endl;
                    break;
                } else
                    continue; // explicitly continuing to accept attempts
            }
        } else {
            cout << "Failure: invalid recipient's card id" << endl;
        }
    } else {
        cout << "Failure: you don't have enough money!" << endl;
    }
    doPressEnterToContinue();
}

void DynamicModel::menuDoChangePhone() {
    cout << "(changing phone...)" << endl;
}

void DynamicModel::menuDoChangePIN() {
    cout << "(changing PIN...)" << endl;
    // string oldPin;
    // cout << "Input old PIN: ";
    // cin >> oldPin; // TODO hide user input
    // const string& cardNumber = atm->currentAccount()->cardNumber();
    // if( atm->check( cardNumber , oldPin) ) {
    //     string newPin;
    //     cout << "Input new PIN: ";
    //     cin >> newPin; // TODO hide user input
    //     string newPinSecond;
    //     cout << "Repeat new PIN: ";
    //     cin >> newPinSecond; // TODO hide user input
    //     if ( newPin.compare(newPinSecond) == 0 ) {
    //         if ( atm->changePIN( cardNumber, oldPin, newPin) ) {
    //             cout << "Password has been changed successfully" << endl;
    //         } else {
    //             cout << "Failure: password was not changed "
    //                  << "(request was declined by the Bank)" << endl;
    //         }
    //     } else {
    //         cout << "Failure: new password inputs do not match" << endl;
    //     }
    // } else {
    //     cout << "Failure: old password is invalid" << endl;
    // }
}

void DynamicModel::menuDoExit() {
    _atm->logout();
    cout << "Bye! Your session has ended. "
         << "Take your card back." << endl;
}

void DynamicModel::menuDoIncorrectOption() {
    cout << "The option is incorrect. Please, select any number of operation "
         << "from the menu" << endl;
    cout << menu;
}

int main() {
    // TODO fill the vector with accounts...
    Bank bank(vector<Account*>{ // TODO change to singleton selector
        new Account("42", "Nassim Taleb", "1111", 10000),
        new Account("24", "Денис Мельниченко", "2222", 20000),
        new Account("55", "Umberto Eko", "3333", 30000, true)
    });
    DynamicModel model(new ATM(bank));
    model.initialize();
    return 0;
}
