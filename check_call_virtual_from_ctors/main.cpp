/*check_call_virtual_from_ctors*/
//https://stackoverflow.com/questions/962132/why-is-a-call-to-a-virtual-member-function-in-the-constructor-a-non-virtual-call
#include <iostream>
#include <string>
using namespace std;

class A
{
public:
  A() { fn(); }

  virtual void fn() { _n = 1; }
  int getn() { return _n; }

protected:
  int _n;
};

class B : public A
{
public:
  B() : A() {}

  virtual void fn() { _n = 2; }
};

int main()
{
  B b;
  int n = b.getn();
  cout << "n=" << n << "\n";
  cout << "One might expect that n is set to 2.It turns out that n is set to 1. Why?\n";
}
