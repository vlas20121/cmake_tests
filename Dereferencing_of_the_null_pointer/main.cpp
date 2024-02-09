//Dereferencing of the null pointer might take place
//https://pvs-studio.ru/ru/docs/warnings/v1032/
#include <iostream>
using namespace std;

bool call_ptr(int* p)
{
    if(!p)
        cout << "\tnullptr exception\n";
    return true;
}
int main()
{
	int *p=nullptr;

    cout << "if (!p && call_ptr(p)) {}\n";
    if (!p && !call_ptr(p)) {}
	cout << "if (!p || !call_ptr(p)){}\n";
	if (!p || !call_ptr(p)){}


    int* pRes = nullptr;
    cout << "if (pRes != NULL || !call_ptr(pRes)){}\n";
    if (pRes != NULL || !call_ptr(pRes)){}
    cout << "if (pRes && !call_ptr(pRes)) {}\n";
    if (pRes && !call_ptr(pRes)) {}
}
