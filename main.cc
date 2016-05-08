#include "rational.h"
#include "irrational.h"
#include "imaginary.h"
#include <iostream>
using namespace std;

int main()
{
	Ratio r(32, 23232);
	Ratio s(1,3);
	cout << Ratio(243, 726) << endl;
	cout << r+s+s*r/s << endl;
	r = s;
	r = r *3;
	if(r == 1) cout << "eq" << endl;
	cout << r << endl;
	int i;
	cin >> i;
	Root ro(i);
	cout << ro << endl;
	Root k = Root(3) - Ratio(2) ;
	Root u = Root(3) + Ratio(2);
	cout << k * Ratio(1,3)<< endl;
	cout <<( Root(3) * Ratio(4) + Ratio(3) )<< endl;
	cout << k << " * " << u << " = " << k*u << endl;
	cout << k << " + " << u << " = " << k+u << endl;
	cout << k << " - " << u << " = " << k-u << endl;
	cout << k << " / " << Root(7)+Root(2) << " = " << (k/(Root(7)+Root(2))) << endl;
	Root a = k;
	cout << a << endl;
	cout << Root(3)/Root(2) << endl;
	Imag im(Root(3), Root(3));
	cout << im << endl;
	cout << im / Imag(Root(3), Root(12))<< endl;

	im = Imag(Root(1), Root(0));
	Imag i2 = Imag(Root(Ratio(3,4)), Root(Ratio(1,4)));
	cout << im << endl << i2 << endl << im * i2 * i2 * i2 <<endl;

}
