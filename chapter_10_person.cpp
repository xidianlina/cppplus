#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "chapter_10_person.h"

Person::Person()
{
	lname = "";
	fname[0] = '\0';
}

Person::Person(const std::string &ln, const char *fn)
{
	lname = ln;
	strcpy(fname, fn);
}

void Person::Show() const
{
	std::cout << "First name is " << fname << " Last name is " << lname << std::endl;
}

void Person::FormalShow() const
{
	std::cout << "Last Name is " << lname << " First Name is " << fname << std::endl;
}