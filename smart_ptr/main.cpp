#include <iostream>
#include <memory>
using namespace std;

static int counter=0;
struct B
{
	B(){cout << id << " B::B()\n";}
	~B(){cout << id << " B::~B()\n";}
    int id = counter++;
};

void t1()
{
	cout << "t1\n";
	std::unique_ptr<B> p1(new B);
}
void t2()
{
	cout << "t2\n";
	std::unique_ptr<B[]> p1(new B[2]);
}
void t3()
{
	cout << "t3\n";
	auto p=std::make_unique<B[]>(3);
	auto &pq=p[1];
}
int main()
{
	t1();
	t2();
	t3();
}
