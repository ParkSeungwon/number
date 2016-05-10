#include "rational.h"
#include "irrational.h"
#include "imaginary.h"
#include <fstream>
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
	Imag thirty(Root(Ratio(3,4),2), (Ratio(1,2)));
	Imag forty(Root(Ratio(1,2),2), Root(Ratio(1,2),2));
	cout << "cos15 + isin15 = " << (sixty / forty) << endl;
	cout << "cos75 + isin75 = " << (thirty * forty) << endl;
	cout <<   (4*Root(3,2)+3).approx()  << endl;
	cout << Root(31,2).approx() << endl;
	Imag tmp;
	for(int j=0; j<arg; j++) {
		for(int i=0; i<arg-j; i++) {
			v.push_back(j * sixty + i);
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
					cout << a << "   " <<  v[i] << "  " << v[j] << "  " << v[k] << endl;
				}
			}
		}
	}
	cout << l << " out of " << m << endl;

	{
		int a = 3, b = 2, c = -1, D;
		D = b*b-4*a*c;
		if(D<0) D = -D;
		Root r(D, 2);
		cout << "3x^2 + 2x -1 = 0 " << "의 해는 ";
		cout << (r-b)/(2*a) << ", ";
		cout << (Root(0)-r-b)/(2*a) << endl;
	}
	
	{
		Ratio r;
		for(int i=2; i<=1024; i*=2) r = r + Ratio(1, i);
		cout << r << endl;
	}

	{
		ofstream of("wri.txt");
		for(auto& a : v) of << a << endl;
	}

	{
		Ratio r(1);
		for(int i=0; i<6; i++) {
			r = (2*r +3)/(3*r+4);
			cout << r << ' '<< endl;
		}
	}
}
