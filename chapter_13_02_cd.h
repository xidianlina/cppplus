#ifndef CD_H_
#define CD_H_
#include <iostream>

class Cd
{
private:
	char *performers;
	char *label;
	int selections;
	double playtime;
public:
	Cd(const char *s1 = "null", const char *s2 = "null", int n = 0, double x = 0.0);
	Cd(const Cd &d);
	virtual~Cd();
	virtual void Report()const;
	Cd &operator=(const Cd &d);
};

class Classic :public Cd
{
private:
	char *name;
public:
	Classic(const char *na = "null", const char *s1 = "null",const char *s2 = "null", int n = 0, double x = 0.0);
	Classic(const Classic &c);
	virtual ~Classic();
	virtual void Report()const;
	Classic &operator=(const Classic &d);
};

#endif