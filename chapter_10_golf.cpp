#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "chapter_10_golf.h"

Golf::Golf()
{
	fullname[0] = '\0';
	handicap = 0;
}

Golf::Golf(const char *fn, const int hc)
{
	strcpy(fullname, fn);
	handicap = hc;
}

int Golf::setGolf()
{
	char fn[Len];
	int hc;

	std::cout << "Enter fullname: ";
	std::cin.getline(fn, Len);
	std::cout << "Enter handicap: ";
	std::cin >> hc;
	Golf g(fn, hc);
	*this = g;
	return fn[0] == 0 ? 0 : 1;
}

void Golf::setHandicap(const int hc)
{
	handicap = hc;
}

void Golf::showGolf()const
{
	std::cout << "Fullname is " << fullname << std::endl;
	std::cout << "Handicap is " << handicap << std::endl;
}