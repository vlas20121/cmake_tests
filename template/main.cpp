#include <iostream>
#include <memory>
using namespace std;

namespace epsilon_compare
{
    template <typename T>
    bool equal(T x, T y, T g)
    {
        cout << "equal\n";
        return true;
    }

    template <typename T>
    bool equal(T x, T y, int g)
    {
        cout << "equal.int\n";
        return true;
    }
}

int main()
{
    epsilon_compare::equal(1., 1., 1.);
    epsilon_compare::equal(1., 1., 1);
    epsilon_compare::equal(1.0f, 1.0f, 1E-6);
}
