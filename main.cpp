#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "json.hpp"

//using namespace std;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using json = nlohmann::json;


class Account {
  string _cardNumber = "1234 1234 1234 1234";
  string _fullName = "Бублик Володимир Васильович";
  int _balance = 42; // TODO change to Money type
  string _phoneNumber = "1234567890";
  friend void from_json(const json& j, Account& s);
  friend void to_json(json& j, const Account& a);
};

void from_json(const json& j, Account& a) {
  a._cardNumber = j["card_number"];
  a._fullName = j["full_name"];
  a._balance = j["balance"];
  a._phoneNumber = j.at("phone_number");
}

void to_json(json& j, const Account& a) {
  j = json{
    {"card_number", a._cardNumber},
    {"full_name", a._fullName},
    {"balance", a._balance},
    {"phone_number", a._phoneNumber}
  };
}

class Session {
private:
  Account& _account;
  vector<string> _history; // TODO change from string to CompletedAction
public:
  Session(Account& a): _account(a) {}
  void writeToFile(string);
  const vector<string> getHistory() const { return _history; }
  const Account& getAccount() const { return _account; }
  void pushAction(const string& s) { _history.push_back(s); } // TODO type
};

void to_json(json& j, const Session& s) {
  j = json{
    {"id", 42}, // TODO
    {"date", "2017-10-14"}, // TODO
    {"account", s.getAccount()},
    {"history", s.getHistory()}
  };
}

void Session::writeToFile(string fname) {
  std::ofstream out(fname);
  json j = *this;
  out << std::setw(2) << j << endl;
}

int main() {
  Account a;
  Session s(a);
  s.pushAction("login");
  s.pushAction("password changed");
  s.pushAction("transfer from X to Y");
  s.pushAction("logout");
  json j = s;
  cout << std::setw(2) << j << endl;
  s.writeToFile("session_history.json");
  return 0;
}
