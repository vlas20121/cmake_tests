#include <iostream>
#include <string>
#include <cmath>
using namespace std;

inline double safeDivide( double a, double b)
{
  if (a == 0.)
    return 0.;
  
  if (b != 0.)
  {
    // Binary exponent of 1.e+300 (value which can be safely represented
    // by IEEE double. Note that even if on some platforms double can represent
    // larger values they are saved to a .dwg file as IEEE where
    // DBL_MAX = 1.7976931348623158e+308 and DBL_MAX_EXP = 1024
    static const int maxBinExp = 997;
    int nExpA, nExpB;
    double dMantissa = frexp(a, &nExpA);
    dMantissa = frexp(b, &nExpB);
    (void)dMantissa;
    if ((nExpA - nExpB) < maxBinExp)
      return a / b;
  }

  bool bNeg = (a < 0.);
  if (b < 0.)
    bNeg = !bNeg;

  return bNeg ? -1.e+300 : 1.e+300;
}

int main()
{
	double d11=safeDivide(1.e+300, 1.e-300);
	double d12=1.e+300 / 1.e-300;
	cout << d11 << "\n";
	cout << d12 << "\n";

	double d21=safeDivide(1.e-300, 1.e+300);
	double d22=1.e-300 / 1.e+300;
	cout << d21 << "\n";
	cout << d22 << "\n";
}
