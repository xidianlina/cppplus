#ifndef WINE_H_
#define WINE_H_
#include <iostream>
#include <string>
#include <valarray>

using namespace std;

template<class T1,class T2>
class Pair
{
private:
	T1 year;
	T2 bottles;
public:
	Pair(const T1 &yr, const T2 &bt) :year(yr), bottles(bt) {}
	Pair() {}
	void Set(const T1 &yr, const T2 &bt);
	int Sum()const;
	void Show(int y)const;
};

template <class T1,class T2>
void Pair<T1, T2>::Set(const T1 &yr, const T2 &bt)
{
	year = yr;
	bottles = bt;
}

template<class T1,class T2>
int Pair<T1, T2>::Sum()const
{
	return bottles.sum();
}

template<class T1,class T2>
void Pair<T1, T2>::Show(int y)const
{
	for (int i = 0; i < y; i++)
		cout << "\t" << year[i] << "\t" << bottles[i] << endl;
}

typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine :private PairArray, private string
{
private:
	int yrs;
public:
	Wine() {}
	Wine(const char *l, int y, const int yr[], const int bot[]);
	Wine(const char *l, int y);
	void GetBottles();
	string &Label();
	void Show()const;
	int sum()const;
};
#endif

Wine::Wine(const char *l,int y,const int yr[],const int bot[]):string(l),yrs(y),PairArray(ArrayInt(yr,y),ArrayInt(bot,y)){}
Wine::Wine(const char *l, int y) : string(l), yrs(y) {}
void Wine::GetBottles()
{
	ArrayInt yr(yrs), bt(yrs);
	cout << "Enter " << Label() << " data for " << yrs << " year(s):\n";
	for (int i = 0; i < yrs; i++)
	{
		cout << "Enter year: ";
		cin >> yr[i];
		cout << "Enter bottles for that year: ";
		cin >> bt[i];
	}
	while (cin.get() != '\n')
		continue;
	PairArray::Set(yr, bt);
}
string &Wine::Label()
{
	return (string &)(*this);
}
void Wine::Show()const
{
	cout << "Wine: " << (string &)(*this) << endl;
	cout << "\tYear\tBottles\n";
	PairArray::Show(yrs);
}
int Wine::sum()const
{
	return PairArray::Sum();
}

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "Enter name of wine: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years: ";
	int yrs;
	cin >> yrs;

	Wine holding(lab, yrs);
	holding.GetBottles();
	holding.Show();

	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };

	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	cout << "Total bottles for " << more.Label() << ": " << more.sum() << endl;
	cout << "Bye\n";

	return 0;
}