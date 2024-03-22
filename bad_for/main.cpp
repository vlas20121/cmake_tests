#include <vector>
#include <iostream>
void main()
{
	std::vector<double> numbers={0,1,2,3,4,5,6,7,8,9};
	double sum=0;
	for (size_t i = numbers.size()-1; i>=0; --i) 
		sum+=numbers[i];
	std::cout << sum << "\n";
}
