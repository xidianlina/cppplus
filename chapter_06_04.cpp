#include <iostream>

using namespace std;

const int strsize = 30;

struct bop {
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference;
};

void showmenu();
void display_by_name(bop *,int);
void display_by_title(bop *, int);
void display_by_bopname(bop *, int);
void display_by_preference(bop *, int);

int main()
{
	const int size = 5;

	bop member[size] = 
	{
		{ "Wimp Macho","English Teacher","DEMON",0 },
		{ "Raki Rhodes","Junior Traninee","BOOM",1 },
		{ "Celia Laiter","Super Star","MIPS",2 },
		{ "Hoppy Hipman","Analyst Trainee","WATEE",1 },
		{ "Pat Hand","Police","LOOPY",2 }
	};
	showmenu();
	char ch;
	while (cin >> ch&&ch != 'q')
	{
		switch (ch)
		{
			case 'a':
				display_by_name(member, size);
				break;
			case 'b':
				display_by_title(member, size);
				break;
			case 'c':
				display_by_bopname(member, size);
				break;
			case 'd':
				display_by_preference(member, size);
				break;
		}
		cout << "Next choice: ";
	}
	cout << "Bye!\n";

	return 0;
}

void showmenu()
{
	cout << "Benevolent Order of Programmers Report\n"
	<< "a.display by name     b.displaybytitle\n"
	<< "c.display by bopname  d.diplaybypreference\n"
	<< "q.quit\n";
	cout << "Enter your choice: ";
}

void display_by_name(bop *member,int n)
{
	int i;

	for (i = 0; i < n; i++)
		cout << member[i].fullname << endl;
}

void display_by_title(bop *member, int n)
{
	for (int i = 0; i < n; i++)
		cout << member[i].title << endl;
}

void display_by_bopname(bop *member, int n)
{
	for (int i = 0; i < n; i++)
		cout << member[i].bopname << endl;
}

void display_by_preference(bop *member, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (member[i].preference == 0)
			cout << member[i].fullname << endl;
		else if (member[i].preference == 1)
			cout << member[i].title << endl;
		else if (member[i].preference == 2)
			cout << member[i].bopname << endl;
	}
}