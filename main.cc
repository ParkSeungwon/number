#include "rational.h"
#include "irrational.h"
#include "imaginary.h"
#include <iostream>
using namespace std;

int main()
{
	vector<Imag> v;
	Imag one(1);
	Imag sixty((Ratio(1,2)), (Root(Ratio(3,4),2)));
	Imag zero;
	Imag tmp;
	for(int j=0; j<7; j++) {
		for(int i=0; i<7-j; i++) {
			v.push_back(zero + (sixty * Imag(j)) + Imag(i));
		}
	}
	for(auto& a : v) cout << a << endl;
	cout << v.size() << endl;
	int l = 0; 
	Root a,b,c;
	for(int i=0; i<28; i++) {
		for(int j=0; j<28; j++) {
			for(int k=0; k<28; k++) {
				a = (v[i]-v[j]).abs();
				b = (v[j]-v[k]).abs();
				c = (v[k]-v[i]).abs();
				if(a == b && b == c && !(a == 0)) {
					l++;
					cout << v[i] << v[j] << v[k] << endl;
					cout << a << b << c << endl;
				}
			}
		}
	}
	cout << l << endl;
}
