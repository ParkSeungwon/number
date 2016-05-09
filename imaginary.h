#pragma once
#include <ostream>
#include "irrational.h"

class Imag
{
public:
	Imag(Root r = 0, Root i = 0);
	Imag operator+(const Imag& im);
	Imag operator-(const Imag& im);
	Imag operator*(const Imag& im);
	Imag operator/(const Imag& im);
	friend std::ostream& operator<<(std::ostream& o, const Imag& i);
	Root real, imag;
	Root abs() {return Root(real*real + imag*imag);}

protected:
};
