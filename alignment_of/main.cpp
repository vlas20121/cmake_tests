/*check_call_virtual_from_ctors*/
//https://pvs-studio.ru/ru/docs/warnings/v1032/
#include <iostream>
#include <string>
#include <cstddef>
#include <type_traits>
#include <typeinfo>
#include <stdalign.h>
using namespace std;

template<class T> void dump_alignment_of()
{
	std::cout << typeid(*(T*)0).name() << ":" << alignment_of<T>::value << "\n";
}
void dump()
{
	dump_alignment_of<char>();
	dump_alignment_of<wchar_t>();
    dump_alignment_of<int>();
    dump_alignment_of<float>();
    dump_alignment_of<double>();
    dump_alignment_of<nullptr_t >();

    dump_alignment_of<char[10]>();
    dump_alignment_of<int[10]>();
    dump_alignment_of<double[10]>();

    dump_alignment_of<void*>();
    dump_alignment_of<int*>();
    dump_alignment_of<char*>();
}

void char_() {
    char c=0;
    alignas(char)char ch[100] = {0};
    double* ptr1 = (double*)ch;
    *ptr1 = 0.0;
    *ptr1 = *ptr1;
    char* char_ptr = (char*)ptr1;
    bool ok = &ch[0] == char_ptr;
    cout << "char_:" << ok;
    char c1 = 0;
    alignas(char)double ds[10] = { 0 };
    for (int i = 0; i < 10; i++)
    {
        ds[i] = 1;
        ptr1[i] = 1;
    }

}

int main()
{
    dump();
    char_();
}