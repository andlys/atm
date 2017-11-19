#include <iostream>
#include <string>
#include "lib/fmt/format.h"
#include "lib/fmt/printf.h"
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
public:
    DynamicModel(ATM* const atm): _atm(atm) {}
    void initialize(void);
};

void DynamicModel::initialize() {
    while (true) {
        processLogin();
        cin.clear();
        cin.ignore(10000, '\n');
        std::string tmp;
        std::cout << "Press Enter to continue" << endl;
        std::getline (std::cin, tmp);
    }
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
            cout << "Can't proceed: your account is blocked. "
                    "Contact the service to resolve the issue." << endl;
            return;
        }
        processPINInput();
    } else {
        cout << "Can't proceed: incorrect card id" << endl;
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
                cout << "You have exceeded three attempts! Card is blocked!" << endl;
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
    cout << "Bye! Your session has ended successfully. " << endl
         << "Take your card back." << endl;
}

void DynamicModel::menuDoPrintBalance() {
    cout << "(printing balance...)" << endl;
}

void DynamicModel::menuDoWithdraw() {
	int cash = 0;
	cout << "Enter the amount you want to withdraw: " << endl;
	while (!(cin >> cash) || cash < 0)
	{
		cout << "Bad input - try again: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	cout << "Please wait ..." << endl;
	cout << _atm->withdrow(Money(cash * 100)) << endl;
}

void DynamicModel::menuDoTransfer() {
    cout << "(transfering money...)" << endl;
}

void DynamicModel::menuDoChangePhone() {
    cout << "(changing phone...)" << endl;
}

void DynamicModel::menuDoChangePIN() {
    cout << "(changing PIN...)" << endl;
}

void DynamicModel::menuDoExit() {
    // TODO end session, etc...
    cout << "(exiting...)" << endl;
}

void DynamicModel::menuDoIncorrectOption() {
    cout << "The option is incorrect. Please, select any number from the menu"
         << endl;
    cout << menu;
}

int main() {
	DynamicModel model(new ATM(Bank(vector<Account*>{})));
    model.initialize();
    return 0;
}
