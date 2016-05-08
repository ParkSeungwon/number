#pragma once
#include <ostream>
#include "irrational.h"

class Imag
{
public:
	Imag(Root r, Root i);
	Imag() {}
	Imag operator+(const Imag& im);
	Imag operator-(const Imag& im);
	Imag operator*(const Imag& im);
	Imag operator/(const Imag& im);
	friend std::ostream& operator<<(std::ostream& o, const Imag& i);

protected:
	Root real, imag;
};
