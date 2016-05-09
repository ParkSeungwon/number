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
	cout << Root(2) * Ratio(3, 2) << endl;
	cout << r << endl;
	Root ro(4);
	cout << ro << endl;
	Root k = Root(3,2) * 2 + 3 ;
	Root u = Root(2, 2) * 4 + 2;
	cout << k << '/' << u << '=' << k/u << endl;
	cout << k << endl;
	cout <<( Root(3) * Ratio(4)  )<< endl;
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
	cout << "here" << endl;
	im = Imag(Root(1), Root(0));
	Imag i2 = Imag(Root(Ratio(3,4)), Root(Ratio(1,4)));
	cout << im << endl << i2 << endl << im * i2 * i2 * i2 <<endl;
	cout << im.abs() << endl;
	
	vector<Imag> v;
	Imag one(1, 0);
	Imag sixty((Ratio(1,2)), (Root(Ratio(3,4),2)));
	Imag im3(Root(0), Root(0));
	v.push_back(im);
	Imag tmp;
	for(int j=7; j>0; j--) {
	for(int i=0; i<j; i++) {
		tmp = im + one;
		v.push_back(tmp);
		tmp = im * sixty;
		v.push_back(tmp);

	}}

}
