#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

class Person
{
private:
	string firstname;
	string lastname;
protected:
	virtual void Data()const;
	virtual void Get();
public:
	Person() :firstname("no one"), lastname("no one") {}
	Person(const string &f, const string &l) :firstname(f), lastname(l) {}
	Person(const Person &p) :firstname(p.firstname), lastname(lastname) {}
	virtual ~Person() = 0;
	virtual void Set() = 0;
	virtual void Show()const = 0;
};

class Gunslinger:virtual public Person
{
private:
	int numsk;
protected:
	void Data()const;
	void Get();
public:
	Gunslinger() :numsk(0),Person() {}
	Gunslinger(int nk, const string &f, const string &l) :numsk(nk), Person(f, l) {}
	Gunslinger(int nk, const Person &p) :numsk(nk),Person(p) {}
	void Show()const;
	void Set();
	double Draw()const;
};

class PokerPlayer:virtual public Person
{
protected:
	void Data()const;
public:
	PokerPlayer() :Person() {}
	PokerPlayer(const string &f, const string &l) : Person(f, l) {}
	PokerPlayer(const Person &p) :Person(p) {}
	int Draw()const;
	void Show()const;
	void Set() { Person::Set(); }
};

class BadDude:public Gunslinger, public PokerPlayer
{
protected:
	void Data()const;
	void Get();
public:
	BadDude() {}
	BadDude(int nk , const string &f, const string &l)	:Person(f, l), Gunslinger(nk, f, l), PokerPlayer(f, l) {}
	BadDude(int nk, const Person &p)	:Person(p), Gunslinger(nk, p), PokerPlayer(p) {}
	BadDude(const Gunslinger &g)	:Person(g),Gunslinger(g),PokerPlayer(g) {}
	BadDude(int nk, const PokerPlayer &po):Person(po), Gunslinger(nk, po), PokerPlayer(po) {}
	double Gdraw()const;
	int Cdraw()const;
	void Set();
	void Show()const;
};

#endif									

Person::~Person() {}

void Person::Data()const
{
	cout << "First name is : " << firstname << endl;
	cout << "Last name is : " << lastname << endl;
}

void Person::Get()
{
	cout << "Enter first name: \n";
	getline(cin, firstname);
	cout << "Enter last name: \n";
	getline(cin, lastname);
}

void Person::Show()const
{
	Data();
}

void Person::Set()
{
	Get();
}

void Gunslinger::Data()const
{
	cout << "Nick is :" << numsk << endl;
	cout << "The time of get the gun :" << Gunslinger::Draw() << endl;
}
void Gunslinger::Get()
{
	cout << "Enter Nick: \n";
	cin >> numsk;
}

void Gunslinger::Set()
{
	cout << "Enter Guns name: \n";
	Person::Get();
	Get();
}

void Gunslinger::Show()const
{
	cout << "Gunslinger: \n";
	Person::Data();
	Data();
}

double Gunslinger::Draw()const
{
	return rand() % 3 + 1;
}

int PokerPlayer::Draw()const
{
	return rand() % 52 + 1;
}

void PokerPlayer::Data()const
{
	cout << "The cards :" << Draw() << endl;
}

void PokerPlayer::Show()const
{
	cout << "PokerPlayer :\n";
	Person::Data();
	Data();
}

double BadDude::Gdraw()const
{
	return Gunslinger::Draw();
}
int BadDude::Cdraw()const
{
	return PokerPlayer::Draw();
}

void BadDude::Data()const
{
	Gunslinger::Data();
	PokerPlayer::Data();
	cout << "The next cards: " << Cdraw() << endl;
	cout << "The time of BadDude get the gun: " << Gdraw() << endl;
}
void BadDude::Get()
{
	Gunslinger::Get();
}

void BadDude::Set()
{
	cout << "Enter BadDude name: \n";
	Person::Get();
	Get();
}
void BadDude::Show()const
{
	cout << "BadDude: \n";
	Person::Data();
	Data();
}

const int Size = 3;

int main()
{
	Person *per[Size];
	int ct;
	for (ct = 0; ct< Size; ct++)
	{
		char choice;
		cout << "Enter the Person: \n"
			<< "g: gunslinger   p: poker  "
			<< "b: bad dude   q: quit\n";
		cin >> choice;
		while (strchr("gpbq", choice) == NULL)
		{
			cout << "Please enter a p,g,o,q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
			case'g':
				per[ct] = new Gunslinger;
				break;
			case'p':
				per[ct] = new PokerPlayer;
				break;
			case'b':
				per[ct] = new BadDude;
				break;
		}
		cin.get();
		per[ct]->Set();
	}
	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i<ct; i++)
	{
		cout << endl;
		per[i]->Show();
	}
	for (i = 0; i<ct; i++)
		delete per[i];
	cout << "Bye\n";

	return 0;
}