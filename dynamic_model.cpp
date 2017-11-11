#include <iostream>
#include <string>
#include "lib/fmt/format.h"
#include "lib/fmt/format.cc"
#include "lib/fmt/printf.h"
#include "lib/fmt/printf.cc"

//using namespace std;
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
                  "0 - exit and release card\n"
                  );
const string greetingPattern("Login successful\n\n"
                             "Greetings, dear %s!\n\n");

// TODO make it singleton?
class DynamicModel {
private:
  ;
  // TODO add ATM, Bank as fields
  void processLogin(void);
  void processMenuInteraction(void);
public:
  void initialize(void);
};

void DynamicModel::initialize() {
  cout << "Hello! Please, sign in." << endl;
  cout << "Input card id: ";
  string card_id;
  cin >> card_id;
  if (card_id == "42" || card_id == "24") {
    bool isAccountBlocked = card_id == "24";
    // TODO ask bank if there exists a user with the given card_id
    // TODO if the user is blocked then show the message and forbid login for this card
    if (isAccountBlocked) {
      cout << "Your account is blocked. "
              "Contact the service to resolve the issue." << endl;
      return;
    }
    for (unsigned int attempsLeft = 3; ; ) {
      string pin;
      cout << "Input PIN: ";
      cin >> pin; // TODO hide user input
      if (pin == "1111") { // TODO ask bank if the user with the given card_id has the password
        fmt::printf(greetingPattern, "Денис Мельниченко");
        cout << menu;
        break; // stop stop asking for PIN
      } else {
        if (!--attempsLeft) {
          cout << "You have exceeded three attempts! Card is blocked!" << endl;
          break; // stop asking for PIN
        } else {
          fmt::printf("Incorrect PIN, %s attemps left\n", attempsLeft);
        }
      }
    }
  } else {
    cout << "Can't read card: incorrect card id" << endl;
  }
}

int main() {
  DynamicModel model;
  //while (true) { // TODO make endless loop
    model.initialize();
    //cout << "Press Enter to continue" << endl;
    // TODO rewrite the two lines below
    //char c;
    //cin >> c;
  //}
  return 0;
}
