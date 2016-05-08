#pragma once
#include <vector>
#include <ostream>

class Ratio
{
public:
	Ratio(int n, int den = 1);
	Ratio() {n=0; den=1;}
	Ratio operator+(const Ratio& r);
	Ratio operator-(const Ratio& r);
	Ratio operator*(const Ratio& r);
	Ratio operator/(const Ratio& r);
	Ratio operator=(const Ratio& r);
	bool operator==(const Ratio& r) {return (n == r.n) && (den == r.den);}
	bool operator>(const Ratio& r);
	bool operator<(const Ratio& r);
	bool operator==(int r) { return (n == r) && (den == 1); }
	Ratio operator+(int r);
	Ratio operator-(int r);
	Ratio operator*(int r);
	Ratio operator/(int r);

	friend std::ostream& operator<<(std::ostream& ostr, const Ratio& rhs);
	int n, den;

protected:
	std::vector<unsigned> prime_div(int num);

private:
};
