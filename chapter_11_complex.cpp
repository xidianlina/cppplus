#include "chapter_11_complex.h"

Complex::Complex()
{
	real = 0.0;
	imag = 0.0;
}

Complex::Complex(double r)
{
	real = r;
	imag = 0.0;
}

Complex::Complex(double r, double i)
{
	real = r;
	imag = i;
}

Complex::~Complex()
{
}

Complex Complex::operator+(const Complex &c)const
{
	return Complex(real + c.real, imag + c.imag);
}

Complex Complex::operator-(const Complex &c)const
{
	return Complex(real - c.real, imag - c.imag);
}

Complex Complex::operator*(const Complex &c)const
{
	double r;
	double i;
	r = real*c.real - imag*c.imag;
	i = real*c.imag + imag*c.real;
	return Complex(r, i);
}
Complex Complex::operator*(double n)const
{
	return Complex(n*real, n*imag);
}
Complex Complex::operator~()const
{
	return Complex(real, -imag);
}
Complex operator*(double n, const Complex &c)
{
	return Complex(n*c.real, n*c.imag);
}
std::ostream &operator<<(std::ostream &os, const Complex &c)
{
	os << "(" << c.real << "," << c.imag << "i)";

	return os;
}

std::istream &operator>>(std::istream &is, Complex &c)
{
	std::cout << "real: ";
	if (is >> c.real)
	{
		std::cout << "imaginary: ";
		is >> c.imag;
	}

	return is;
}