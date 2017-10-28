#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "chapter_12_cow.h"

Cow::Cow()
{
	name[0] = '\0';
	hobby = nullptr;
	weight = 0;
}

Cow::Cow(const char *nm, const char*ho, double wt)
{
	strcpy(name, nm);
	hobby = new char[strlen(ho) + 1];
	strcpy(hobby, ho);
	weight = wt;
}

Cow::Cow(const Cow &c)
{
	strcpy(name, c.name);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{
	delete[]hobby;
}

Cow &Cow::operator=(const Cow &c)
{
	if (this == &c)
		return *this;
	delete[]hobby;
	hobby = new char[strlen(c.hobby) + 1];
	strcpy(hobby, c.hobby);
	strcpy(name, c.name);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow()const
{
	std::cout << "Name is " << name << std::endl;
	std::cout << "Hobby is " << hobby << std::endl;
	std::cout << "Weight is " << weight << std::endl;
}