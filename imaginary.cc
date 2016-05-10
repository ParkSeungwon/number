#include "imaginary.h"
using namespace std;

Imag::Imag(Root r, Root i)
{
	real = r;
	imag = i;
}

Imag Imag::operator+(const Imag& im)
{
	Imag i;
	i.real = real + im.real;
	i.imag = imag + im.imag;
	return i;
}

Imag Imag::operator-(const Imag& im)
{
	Imag i;
	i.real = real - im.real;
	i.imag = imag - im.imag;
	return i;
}

Imag Imag::operator*(const Imag& im)
{
	Imag i;
	i.real = real * im.real - imag * im.imag;
	i.imag = real * im.imag + imag * im.real;
	return i;
}

Imag Imag::operator/(const Imag& im2)
{
	Imag i, im = im2; 
	im.imag = Root(0) - im.imag;
	i = *this * im;
	i.real = i.real / (im.real * im.real + im.imag * im.imag);
	i.imag = i.imag / (im.real * im.real + im.imag * im.imag);
	return i;
}

ostream& operator<<(ostream& o, const Imag& im)
{
	o << '(' << im.real << ")+(" << im.imag << ')' << 'i';
	return o;
}
