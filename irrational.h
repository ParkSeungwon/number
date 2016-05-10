#pragma once
#include <map>
#include "rational.h"

class Root 
{
public:
	Root(unsigned i = 0, unsigned e = 1);
	Root(Ratio r, unsigned e = 1);
	friend std::ostream& operator<<(std::ostream& o, const Root& rhs);
	Root operator+(const Root& r);
	Root operator-(const Root& r);
	Root operator*(const Root& r);
	Root operator/(const Root& r);
	bool operator==(const Root& r);
	bool operator<(const Root& r);
	bool operator>(const Root& r);
	bool operator<=(const Root& r);
	bool operator>=(const Root& r);
	friend Root operator+(const Root& l, const Root& r);
	friend Root operator-(const Root& l, const Root& r);
	friend Root operator*(const Root& l, const Root& r);
	friend Root operator/(const Root& l, const Root& r);
	bool isRational();
	float approx();
	
protected:
	std::map<unsigned, Ratio> ir;

private:
	void clear_garbage() {
		for(auto& a : ir) if(a.second == 0) ir.erase(a.first);
	}
};
