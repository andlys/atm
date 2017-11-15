#include <iostream>

using namespace std;

class A {
public:
  int n = 5;
  int m() const { return n*n; }
};

int main() {
  A a;
  cout << a.m() << endl;
  const A a2;
  cout << a2.m() << endl;
  /*
  double* const d = new double(2);
  *d = 4; // ok
  double d2 = 10;
  d = &d2; // error: assignment of read-only variable ‘d’
  d;
  */
  //delete d;
  return 0;
}
