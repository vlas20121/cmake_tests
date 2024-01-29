/*check_call_virtual_from_ctors*/

#include <iostream>
#include <string>
using namespace std;

static int l=0;
void ident()
{
	cout << string(l++,' ').c_str();
}

class A{
public:
	A()
	{		
		ident();cout << "A::A()\n";
		int l1=l;
		f();
		l=l1;
		f1();
	}
	virtual void f(){
		ident();cout <<"A::f()\n";
	}
	void f1(){
		ident();cout << "A::f1()\n";
		f();
	}
};

class B: public A{
public:
	B()
	{
		cout << "B::B()\n";
	}
	virtual void f(){
		ident();;cout << "B::f()\n";
	}
};

int main() { 
	B b;
	return 0; 
}
