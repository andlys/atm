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
    void processLogin(void);
    void processPINInput(void);
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
    // while (true) {
        processLogin();
        // doPressEnterToContinue();
    // }
}

void DynamicModel::processLogin() {
    cout << "Hello! Please, sign in." << endl;
    cout << "Input card id: ";
    string card_id;
    cin >> card_id;
    if (card_id == "42" || card_id == "24") {
        bool isAccountBlocked = card_id == "24";
        // TODO ask bank if there exists a user with the given card_id
        // TODO if the user is blocked then show the message and forbid login for this card
        if (isAccountBlocked) {
            cout << "Failure: can't proceed since your account is blocked. "
                    "Contact the service to resolve the issue." << endl;
            return;
        }
        processPINInput();
    } else {
        cout << "Failure: can't proceed since card id is incorrect" << endl;
    }
}

void DynamicModel::processPINInput() {
    for (unsigned int attempsLeft = 3; ; ) {
        string pin;
        cout << "Input PIN: ";
        cin >> pin; // TODO hide user input
        if (pin == "1111") { // TODO ask bank if the user with the given card_id has the password
            processMenuInteraction(); // login successful
            break; // stop asking for PIN
        } else {
            if (!--attempsLeft) {
                cout << "Failure: you have exceeded three attempts! Card is blocked!" << endl;
                break; // stop asking for PIN
            } else {
                fmt::printf("Incorrect PIN, %s attemps left\n", attempsLeft);
            }
        }
    }
}

void DynamicModel::processMenuInteraction() {
    fmt::printf(greetingPattern, "Денис Мельниченко");
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
    // fmt::printf("Your balance is %f %s",
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
    cin >> amount; // TODO loop until data is valid - valid???
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
    cout << "Input amount of money to transfer (floating point, precision up to 0.01): ";
    double amount;
    while (true) {
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> amount;
        if ( (long(amount*100) % 1 != 0) || (amount < 0) )
            cout << "Invalid amount!" << endl;
        else
            break;
    }
    Money money(amount * 100); // double to coins
    // TODO Money copying constructor;
    // BEWARE: it is resposibility of ATM and Bank to withdraw commission!
    // check if enough money (including commission)
    // Account* const recipient = atm->getAccountById();
    // check if recipient is not blocked!
    // if (account) {
    //     fmt::printf("Are you sure to make a transer of %f %s to #%s (%s)",
    //         double(money), money->code(),
    //         recipient->cardNumber(), recipient->fullName());
    //     // cin  y/n
    //     if ( atm->transer(recipientCardId, money) )
    //         cout << "Success!" << endl;
    //     else
    //         cout << "Failure: request was declined by ATM!" << endl
    // } else {
    //     cout << "Invalid recipient's card id" << endl;
    // }
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
    DynamicModel model(new ATM(new Bank(vector<Account*>{})));
    model.initialize();
    return 0;
}
