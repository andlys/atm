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
  // TODO make proper incapslulation
public:
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

// temporarily no more than one single instance of a bank can be supported
// and only with a name of "ПриватБанк"
class Bank {
private:
  // file name where all accounts of all banks are sotred
  static const string _accountsFile;
  const string _name;
public:
  Bank(const string& name): _name(name) {}
  // returns vector of all accounts of this bank
  vector<Account> getAccounts(); // TODO private
  void pushAccount(const Account& a); // TODO private
};

const string Bank::_accountsFile("accounts.json");


vector<Account> Bank::getAccounts() {
  json j;
  try {
    std::ifstream in(_accountsFile);
    in >> j;
  } catch (const std::invalid_argument& arg) {
    cout << "ERROR: file " << _accountsFile << " is missing" << endl;
  }
  if (j.empty() || j.at("accounts").empty())
    return vector<Account>();
  else
    return j.at("accounts").get<vector<Account>>();
}

void Bank::pushAccount(const Account& a) {
  vector<Account> allAccounts = getAccounts();
  allAccounts.push_back(a);
  json j = {
    {"bank", _name},
    {"accounts", allAccounts}
  };
  std::ofstream out(_accountsFile);
  out << std::setw(2) << j << endl;
}

/*
void prototypePush() {
  json j = {
    {
      {"bank", "Ощадбанк"},
      {"accounts", {}}
    },
    {
      {"bank", "ПриватБанк"},
      {"accounts", {}}
    },
    {
      {"bank", "Райффайзен Аваль"},
      {"accounts", {}}
    }
  };
  std::ofstream out("accounts.json");
  out << std::setw(2) << j << endl;
}
*/

void prototypePush() {
  json j = {
    {"bank", "ПриватБанк"},
    {"accounts", {}}
  };
  std::ofstream out("accounts.json");
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
  cout << "session object converted to JSON:" << endl
       << std::setw(2) << j << endl;
  s.writeToFile("session_history.json");
  //prototypePush();

  Bank superBank("ПриватБанк");
  Account acc;
  acc._fullName = "Мельниченко Денис Батькович";
  acc._balance = 1100;
  superBank.getAccounts();
  superBank.pushAccount(acc);
  superBank.pushAccount(Account());
  cout << "Now check out accounts.json file!" << endl;
  return 0;
}
