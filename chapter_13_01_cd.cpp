#define _CRT_SECURE_NO_WARNINGS
#include "chapter_13_01_cd.h"

Cd::Cd(char *s1, char *s2, int n, double x)
{
	std::strcpy(performers, s1);
	std::strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd &d)
{
	std::strcpy(performers, d.performers);
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

void Cd::Report()const
{
	std::cout << "performers: " << performers << std::endl;
	std::cout << "label: " << label << std::endl;
	std::cout << "selections: " << selections << std::endl;
	std::cout << "playtime: " << playtime << std::endl;
}

Cd &Cd::operator=(const Cd &d)
{
	if (this == &d)
		return *this;
	std::strcpy(performers, d.performers);
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;

	return *this;
}

Classic::Classic(const Classic &c) :Cd(c)
{
	std::strcpy(name, c.name);
}

void Classic::Report()const
{
	std::cout << "name: " << name << std::endl;
	Cd::Report();
}

Classic &Classic::operator=(const Classic &d)
{
	if (this == &d)
		return *this;
	Cd::operator=(d);
	std::strcpy(name, d.name);
	return *this;
}