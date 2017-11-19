#include <iostream>
#include "Money.h"

using namespace std;

int main() {
    Money m1(1);
    cout << m1.coins() << endl;
    cout << double(m1) << endl;
    Money m2(5575);
    cout << m2.coins() << endl;
    cout << double(m2) << endl;
    cout << boolalpha << (m1 >= m2) << endl;
    cout << boolalpha << (Money(5575) >= m2) << endl;

    Money m3 = (Money (6666)) * 100;
    cout << m3.coins() << endl;
    cout << double(m3) << endl;
    cout << m3.code() << endl;

    Money comission = (Money (10000)) * 3;
    cout << comission.coins() << endl;
    cout << double(comission) << endl;

    cout << ((Money (250)) += (Money (175))).coins() << endl;
    cout << double ((Money (250)) += (Money (175))) << endl;
    return 0;
}
