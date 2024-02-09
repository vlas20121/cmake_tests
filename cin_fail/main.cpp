//https://pvs-studio.ru/ru/docs/warnings/v663/
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    stringstream fPrj("k1 v1\n k2 v2\n k3\t\n\n\n\n\n k4 v4\n");
	std::string name, sVal;

    while (!(fPrj >> name >> sVal).eof())
		cout << name.c_str() << "," << sVal.c_str() << "\n";
}
