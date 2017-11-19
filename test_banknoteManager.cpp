#include "ATM.h"

int main() {
	BanknoteManager *bm = new BanknoteManager();

	cout << bm->getCash(0) << endl;
	cout << bm->getCash(1) << endl;
	cout << bm->getCash(9) << endl;
	cout << bm->getCash(10) << endl;
	cout << bm->getCash(11) << endl;
	cout << bm->getCash(55) << endl;
	cout << bm->getCash(555) << endl;
	cout << bm->getCash(1000) << endl;
	cout << bm->getCash(1001) << endl;
	cout << bm->getCash(10000) << endl;

	delete bm;

	return 0;
}
