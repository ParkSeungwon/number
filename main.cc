#include "rational.h"
#include "irrational.h"
#include "imaginary.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	if(argc < 2) {
		cout << "usage : " << argv[0] << " 한변의 점의 갯수" << endl;
		return 0;
	}
	int arg = atoi(argv[1]);
	vector<Imag> v;
	Imag one(1);
	Imag sixty((Ratio(1,2)), (Root(Ratio(3,4),2)));
	Imag zero;
	Imag tmp;
	for(int j=0; j<arg; j++) {
		for(int i=0; i<arg-j; i++) {
			v.push_back(zero + (sixty * Imag(j)) + Imag(i));
		}
	}
	for(auto& a : v) cout << a << endl;
	int sz = v.size();
	cout << sz << endl;
	int l = 0, m = 0; 
	Root a,b,c;
	for(int i=0; i<sz; i++) {
		for(int j=i+1; j<sz; j++) {
			for(int k=j+1; k<sz; k++) {
				a = (v[i]-v[j]).abs();
				b = (v[j]-v[k]).abs();
				c = (v[k]-v[i]).abs();
				m++;
				if(a == b && b == c) {
					l++;
					cout << v[i] << "  " << v[j] << "  " << v[k] << endl;
					cout << a << b << c << endl;
				}
			}
		}
	}
	cout << l << " out of " << m << endl;

/*	{
		int a,b,c, D;
		cin >> a >> b >> c;
		D = b*b-4*a*c;
		if(D<0) D = -D;
		Root r(D, 2);
		cout << r << endl;
		cout << (r-b)/(2*a) << endl;
		cout << (Root(0)-r-b)/(2*a) << endl;
	}
	*/
}
