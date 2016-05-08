#pragma once
#include <vector>
#include <ostream>

class Ratio
{
public:
	Ratio(int n, int den = 1);
	Ratio();
	Ratio operator+(const Ratio& r);
	Ratio operator+(int r);
	Ratio operator-(int r);
	Ratio operator*(int r);
	Ratio operator/(int r);
	Ratio operator-(const Ratio& r);
	Ratio operator*(const Ratio& r);
	Ratio operator/(const Ratio& r);
	Ratio operator=(const Ratio& r);
	bool operator==(const Ratio& r);
	bool operator==(int r);
	bool operator>(const Ratio& r);
	bool operator<(const Ratio& r);

	template <typename charT, typename traits>
	friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& ostr, const Ratio& rhs)
	{
		if(rhs.den == 1) ostr << rhs.n;
		else ostr << rhs.n << '/' << rhs.den;
		return ostr;
	}

protected:
	std::vector<unsigned> prime_div(int num);

private:
	int n, den;
};
