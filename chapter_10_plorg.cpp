#include <iostream>
#include <cstring>
#include "chapter_10_plorg.h"

Plorg::Plorg()
{
	strcpy_s(name, "");
	ci = 0;
}

Plorg::Plorg(const char *n, int c)
{
	strcpy_s(name, n);
	ci = c;
}

void Plorg::setname(const char *n)
{
	strcpy_s(name, n);
}

void Plorg::setci(const int c)
{
	ci = c;
}

void Plorg::show() const
{
	std::cout << "Name is " << name << " CI is " << ci << std::endl;
}