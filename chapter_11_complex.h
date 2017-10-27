#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>

class Complex
{
private:
	double real;
	double imag;
public:
	Complex();
	Complex(double r);
	Complex(double r, double i);
	~Complex();
	Complex operator+(const Complex &c)const;
	Complex operator-(const Complex &c)const;
	Complex operator*(const Complex &c)const;
	Complex operator*(double n)const;
	Complex operator~()const;

	friend Complex operator*(double n, const Complex &c);
	friend std::ostream &operator<<(std::ostream &os, const Complex &c);
	friend std::istream &operator>>(std::istream &is, Complex &c);
};

#endif