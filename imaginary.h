#pragma once
#include <ostream>
#include "irrational.h"

class Imag
{
public:
	Root real, imag;

	Imag(Root r = 0, Root i = 0);
	Imag(int i);
	Imag operator+(const Imag& im);
	Imag operator-(const Imag& im);
	Imag operator*(const Imag& im);
	Imag operator/(const Imag& im);
	friend Imag operator+(const Imag& l, const Imag& r);
	friend Imag operator-(const Imag& l, const Imag& r);
	friend Imag operator*(const Imag& l, const Imag& r);
	friend Imag operator/(const Imag& l, const Imag& r);
	bool operator==(const Imag& im) {return real == im.real && imag == im.imag;}
	friend std::ostream& operator<<(std::ostream& o, const Imag& i);
	Root abs() {return real*real + imag*imag;}

protected:
};
