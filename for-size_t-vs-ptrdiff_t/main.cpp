#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> indexes={0,1,2,3,4};
	for (auto i = ptrdiff_t(indexes.size()) - 1; i >= 0; --i)
    //for (size_t i = 0; i<indexes.size(); i++)
	{
		cout << indexes[i] << "\n";
	}
}
