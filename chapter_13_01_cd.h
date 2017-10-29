#define _CRT_SECURE_NO_WARNINGS
#ifndef CD_H_
#define CD_H_

#include <iostream>

class Cd
{
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	Cd(char *s1, char *s2, int n, double x);
	Cd(const Cd &d);
	Cd(){}
	virtual ~Cd(){}
	virtual void Report()const;
	Cd &operator=(const Cd &s);
};

class Classic :public Cd
{
private:
	char name[50];
public:
	Classic(char *na, char *s1, char *s2, int n, double x) :Cd(s1, s2, n, x)
	{
		std::strcpy(name, na);
	}
	Classic(char *na, const Cd &d) :Cd(d) { std::strcpy(name, na); }
	Classic(const Classic &c);
	Classic(){}
	virtual void Report()const;
	Classic &operator=(const Classic &d);
};

#endif