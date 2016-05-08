#pragma once
#include <map>
#include "rational.h"

class Root : public Ratio
{
public:
	Root(unsigned i);

	template <typename charT, typename traits>
	friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& ostr, const Root& rhs)
	{
		ostr << rhs;
		for(auto& a : rhs.ir) {
			if(a.first == 1) ostr << a.second;
			//else if(a.second == Ratio(1, 1)) ostr << "_/" << a.first;
			else ostr << a.second << "_/" << a.first;
		}
		return ostr;
	}
	
	
	
protected:
	std::map<unsigned, Ratio> ir;

private:
};
