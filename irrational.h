#pragma once
#include <map>
#include "rational.h"

class Root : public Ratio
{
public:
	Root(unsigned i);
	Root(Ratio r);
	Root() {Root(0);}
	friend std::ostream& operator<<(std::ostream& o, const Root& rhs);
	Root operator+(const Root& r);
	Root operator-(const Root& r);
	Root operator*(const Root& r);
	Root operator/(const Root& r);
	Root operator/(const Ratio& r);
	Root operator*(const Ratio& r);
	Root operator-(const Ratio& r);
	Root operator+(const Ratio& r);
	bool isRational();
	
protected:
	std::map<unsigned, Ratio> ir;

private:
};
