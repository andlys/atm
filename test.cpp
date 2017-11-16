#include <iostream>

using namespace std;

class A {
public:
    A() {}
    A(int i) { _n = i; }
    int _n = 5;
    int n() const { return _n; }
};

// utility
const A operator+=(const A& a, const A& b){
    return A(a.n() + b.n());
}

int main() {
    A a;
    cout << a.n() << endl;
    const A a2;
    cout << a2.n() << endl;
    a._n = 15;
    a2._n = 10;
    a2 += a; // the expr
    cout << a2.n() << endl; // a2 was not modified
    /*
    double* const d = new double(2);
    *d = 4; // ok
    double d2 = 10;
    d = &d2; // error: assignment of read-only variable ‘d’
    d;
    */
    //delete d
    return 0;
}
