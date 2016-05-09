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
	bool isRational();
	std::map<unsigned, Ratio> ir;
	
protected:

private:
};
