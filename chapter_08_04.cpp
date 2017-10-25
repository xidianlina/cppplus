#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

struct stringy {
	char *str;
	int ct;
};

void set(stringy &, char *);
void show(stringy, int n = 1);
void show(char *, int n = 1);

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);

	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");

	return 0;
}

void set(stringy &stry, char *s)
{
	int len = strlen(s);
	char *ps = new char[len + 1];
	stry.str = strcpy(ps, s);
	stry.ct = len;
}

void show(stringy stry, int times)
{
	int n = 1;

	if (times > 1)
		n = times;
	for (int i = 0; i < n; i++)
		cout << stry.str << endl;
}

void show(char *s, int times)
{
	int n = 1;

	if (times > 1)
		n = times;
	for (int i = 0; i < n; i++)
		cout << s << endl;
}