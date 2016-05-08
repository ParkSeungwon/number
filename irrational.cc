#include "irrational.h"
using namespace std;

Root::Root(unsigned i) : Ratio(0) 
{
	auto v = prime_div(i);
	int fr = 1;
	for(auto it = v.begin(); it+1 != v.end() && it != v.end();) {
		if(*it == *(it+1)) {
			fr *= *it;
			it = v.erase(it, it+2);
		} else it++;
	}
	int sum = 1;
	for(auto& a : v) sum *= a;
	ir.insert({sum, Ratio(fr)});
}
	

