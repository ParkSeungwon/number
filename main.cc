#include "rational.h"
#include "irrational.h"
#include <iostream>
using namespace std;

int main()
{
	Ratio r(32, 23232);
	Ratio s(1,3);
	cout << Ratio(243, 726) << endl;
	cout << r+s+s*r/s << endl;
	r = s;
	cout << r << endl;
	int i;
	cin >> i;
	cout << Root(i) << endl;
}
