#include "BanknoteManager.h"
#include <fstream>
#include "lib/json/json.hpp"

using std::cout;
using std::endl;

vector<int> BanknoteManager::amounts() const
{
	vector<int> amount;
	for (auto it = _available.rbegin(); it != _available.rend(); ++it) {
		amount.push_back(it->second.size());
	}
	return amount;
}

const vector<int> BanknoteManager::availableNominals() const {
	vector<int> nominals;
	for (auto it = _available.begin(); it != _available.end(); ++it) {
		if (!it->second.empty()) {
			nominals.push_back(it->first);
		}
	}
	return nominals;
}

vector<Banknote> BanknoteManager::banknotes(vector<int> nominals)
{
	vector<Banknote> banknotesRes;
	int i = 0;
	for (auto it = _available.rbegin(); it != _available.rend(); ++it) {
		for (int j = 0; j < nominals[i]; ++j) {
			banknotesRes.push_back(Banknote{ it->second[(it->second.size() - 1)]._nominal, it->second[(it->second.size() - 1)]._code, it->second[(it->second.size() - 1)]._id });
			it->second.pop_back();
		}
		++i;
	}
	return banknotesRes;
}

bool BanknoteManager::enoughMoney(const unsigned int cash)
{
	unsigned int sumAllMoney = 0;
	for (auto it = _available.begin(); it != _available.end(); ++it) {
		for (int j = 0; j < it->second.size(); ++j) {
			sumAllMoney += it->second[j]._nominal;
		}
	}
	return sumAllMoney >= cash;
}

vector<vector<int>> BanknoteManager::solutions(const vector<int> values, const vector<int> amounts, const vector<int> variation, unsigned int price, int position)
{
	vector<vector<int>> list;
	int value = compute(values, variation);
	if (value < price) {
		for (int i = position; i < values.size(); i++) {
			if (amounts[i] > variation[i]) {
				vector<int> newVariation = variation;
				newVariation[i]++;
				vector<vector<int>> newList = solutions(values, amounts, newVariation, price, i);
				if (!newList.empty()) {
					list.insert(list.end(), newList.begin(), newList.end());
					break;
				}
			}
		}
	}
	else if (value == price) {
		list.push_back(myCopy(variation));
	}
	return list;
}

int BanknoteManager::compute(const vector<int> values, const vector<int> variation)
{
	int ret = 0;
	for (int i = 0; i < variation.size(); i++) {
		ret += values[i] * variation[i];
	}
	return ret;
}

vector<int> BanknoteManager::myCopy(const vector<int> ar)
{
	vector<int> ret(ar.size());
	for (int i = 0; i < ar.size(); i++) {
		ret[i] = ar[i];
	}
	return ret;
}

map<int, vector<Banknote>> BanknoteManager::getBanknotes() {
	map<int, vector<Banknote>> banknotes;
	vector<char*> nominals{ "500", "200", "100", "50", "20", "10", "5", "2", "1" };
	std::ifstream in("banknotes_sample.json");
	if (!in.is_open()) {
		cout << "No such file" << endl;
	}
	else {
		string str((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
		auto j = nlohmann::json::parse(str.c_str());
		auto allBanknotesJSON = j["banknotes"];
		
		for (int i = 0; i < nominals.size(); ++i) {
			auto nominalBanknotes = allBanknotesJSON[nominals[i]];
			vector<Banknote> vNominalBanknotes;
			for (int j = 0; j < nominalBanknotes.size(); ++j) {
				vNominalBanknotes.push_back(Banknote{ nominalBanknotes[j]["nominal"], nominalBanknotes[j]["code"], nominalBanknotes[j]["id"]});
			}
			banknotes.insert(std::pair<int, vector<Banknote>>(atoi(nominals[i]), vNominalBanknotes));
		}
		in.close();
	}
	return banknotes;
}

bool BanknoteManager::updateBanknotes() {
	std::ofstream out("banknotes_sample.json");
	if (!out.is_open()) {
		cout << "No such file!" << endl;
		return false;
	}
	nlohmann::json j;
	j["banknotes"] = { { "1",{} }, { "2",{} }, { "5",{} }, { "10",{} }, { "20",{} }, { "50",{} }, { "100",{} }, { "200",{} }, {"500", {}} };
	for (auto it = _available.begin(); it != _available.end(); ++it) {
		nlohmann::json banknotes;
		for (int i = 0; i < it->second.size(); ++i) {
			banknotes.push_back({
				{ "nominal", it->second[i]._nominal },
				{ "code", it->second[i]._code },
				{ "id", it->second[i]._id },
			});
		}
		j["banknotes"][std::to_string(it->first).c_str()] = banknotes;
	}
	cout << j << endl;
	out << std::setw(2) << j << endl;
	out.close();

	return true;
}

BanknoteManager::BanknoteManager() : _available(BanknoteManager::getBanknotes()) {
	return;
}

BanknoteManager::~BanknoteManager() {
	return;
}

const MoneyDisposal* BanknoteManager::getCash(unsigned int cash)
{
	if (cash == 0 ) return new MoneyDisposal(vector<Banknote>{}, "Operation failed: You are trying to get a zero banknote");
	if (!enoughMoney(cash)) {
		return new MoneyDisposal(vector<Banknote>{}, "Operation failed: Not Enough Money in ATM");
	}
	////500, 200, 100, 50, 20, 10, 5, 2, 1
	vector<int> values = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
	vector<int> amounts = this->amounts();
	vector<vector<int>> banknotesResult = solutions(values, amounts, vector<int>(values.size()), cash, 0);
	if (banknotesResult.size() == 0) {
		return new MoneyDisposal(vector<Banknote>{}, "Operation failed: No such banknotes in ATM");
	}
	vector<Banknote> res = banknotes(banknotesResult[0]);

	return new MoneyDisposal(res, "Successful Withdrawal");
}
