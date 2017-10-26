#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "chapter_09_golf.h"

void setgolf(golf &g, const char *name, int hc)
{
	strcpy(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf &g)
{
	std::cout << "Enter the golfer's name: \n";
	std::cin.get(g.fullname, Len);
	if (g.fullname[0] == '\0')
		return 0;
	std::cout << "Enter the handicap for " << g.fullname << ": " << std::endl;
	while (!(std::cin >> g.handicap))
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "Please enter an integer:\n";
	}
	std::cin.get();

	return 1;
}

void handicap(golf &g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf &g)
{
	std::cout << "fullname is " << g.fullname << std::endl;
	std::cout << "handicap is " << g.handicap << std::endl;
}