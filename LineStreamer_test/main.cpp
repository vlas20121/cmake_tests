#include <string>
#include <iostream>
#include "LineStreamer.h"

int main()
{
	using namespace std;
	int static n=0;
	LineStreamer stream([&](const char* s) {cout << (string("line")+to_string(n++)+":").c_str() << s; });
	for(int i=0;i<100;i++)
		stream << (to_string(i)+"\n").c_str();
}
