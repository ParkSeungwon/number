#include <iostream>
#include "irrational.h"
using namespace std;

Root::Root(unsigned i) : Ratio(0, 1) 
{
	if(i == 0) {
		ir.insert({1, 0});
		return;
	}

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

Root::Root(Ratio r) : Ratio(0, 1)
{
	*this = Root(r.den * r.n) * Ratio(1, r.den);
}

Root Root::operator+(const Root& r)
{
	Root t(*this);
	for(auto& a : r.ir) {
		if(ir.find(a.first) == ir.end()) t.ir[a.first] = a.second;
		else t.ir[a.first] = ir[a.first] + a.second;
	}
	return t;
}

Root Root::operator+(const Ratio& r)
{
	Root t(*this);
	t.ir[1] = ir[1] + r;
	return t;
}

Root Root::operator-(const Ratio& r)
{
	Root t(*this);
	t.ir[1] = ir[1] - r;
	return t;
}

Root Root::operator*(const Ratio& r)
{
	Root t(*this);
	for(auto& a : ir) {//first:inside root, second:ratio
		t.ir[a.first] = a.second * r;
	}
	return t;
}

Root Root::operator/(const Ratio& r)
{
	Root t(*this);
	for(auto& a : ir) {//first:inside root, second:ratio
		t.ir[a.first] = a.second / r;
	}
	return t;
}

Root Root::operator-(const Root& r)
{
	Root t(*this);
	for(auto& a : r.ir) {
		if(ir.find(a.first) == ir.end()) t.ir[a.first] = Ratio(0) - a.second;
		else t.ir[a.first] = ir[a.first] - a.second;
	}
	return t;
}

Root Root::operator*(const Root& r)
{
	Root t(0);
	for(auto& a : ir) {
		for(auto& b : r.ir) {
			t = t + (Root(a.first * b.first) * (a.second * b.second));
		}
	}
	return t;
}

Root Root::operator/(const Root& r)
{
	Root t(r);
	Root tm(r);//up*tm/t*tm
	Root up(1);
	map<unsigned, Ratio>::reverse_iterator it;
	while(!tm.isRational()) {
		it = tm.ir.rbegin();
		it->second = Ratio(0) - it->second;
		up = up * tm;
		t = tm * t;
		tm = t;
	}
	return up * *this / t.ir[1];
}

bool Root::isRational()
{
	for(auto& a : ir) if(a.second == 0) ir.erase(a.first);
	if(ir.size() > 1)  return false;
	else if(ir.size() == 0) return true;
	else if(ir.find(1) != ir.end()) return true;
	else return false;
}
	
ostream& operator<<(ostream& o, const Root& rhs)
{
	for(auto& a : rhs.ir) {
		if(!((Ratio)a.second == 0)) {
			cout << ' ';
			if((Ratio)a.second > 0) cout << '+';
			if(a.first == 1) o << a.second;
			else if((Ratio)a.second == 1) o << "_/" << a.first;//first, second는 자신이 무슨 형식인지 알지못함.
			else if((Ratio)a.second == -1) o << "-_/" << a.first;
			else o << a.second << "_/" << a.first;
		}
	}
	return o;
}
	

