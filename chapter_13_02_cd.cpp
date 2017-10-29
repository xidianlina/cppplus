#define _CRT_SECURE_NO_WARNINGS
#include "chapter_13_02_cd.h"
#include <cstring>

Cd::Cd(const char *s1,const char *s2, int n, double x)
{
	performers = new char[std::strlen(s1) + 1];
	label = new char[std::strlen(s2) + 1];
	std::strcpy(performers, s1);
	std::strcpy(label, s2);
	selections = n;
	playtime = x;
}
Cd::Cd(const Cd &d)
{
	performers = new char[std::strlen(d.performers) + 1];
	std::strcpy(performers, d.performers);
	label = new char[std::strlen(d.label) + 1];
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}
Cd::~Cd()
{
	delete[]performers;
	delete[]label;
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
	delete[] performers;
	delete[] label;
	performers = new char[std::strlen(d.performers) + 1];
	label = new char[std::strlen(d.label) + 1];
	std::strcpy(performers, d.performers);
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

Classic::Classic(const char *na, const char *s1,const char *s2, int n, double x) :Cd(s1, s2, n, x)
{
	name = new char[std::strlen(na) + 1];
	std::strcpy(name, na);
}
Classic::Classic(const Classic &c):Cd(c)
{
	name = new char[std::strlen(c.name) + 1];
	std::strcpy(name, c.name);
}
Classic::~Classic()
{
	delete[]name;
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
	delete[]name;
	name = new char[std::strlen(d.name) + 1];
	std::strcpy(name, d.name);
	return *this;
}