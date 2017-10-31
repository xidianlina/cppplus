#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_

#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>

using namespace std;

class bad_hmean :public logic_error
{
private:
	string name;
public:
	explicit bad_hmean(const string &n = "hmean", const string &s = "Error in hmean()\n");
	string mesg();
	virtual ~bad_hmean()throw(){}
};

bad_hmean::bad_hmean(const string &n,const string &s):name(n),logic_error(s){}
inline string bad_hmean::mesg()
{
	return "hmean() arguments a=-b should be div a+b=0!\n";
}

class bad_gmean :public logic_error
{
private:
	string name;
public:
	explicit bad_gmean(const string &n = "gmean", const string &s = "Error in gmean()\n");
	string mesg();
	virtual ~bad_gmean()throw() {}
};

bad_gmean::bad_gmean(const string &n,const string &s):name(n),logic_error(s){}
inline string bad_gmean::mesg()
{
	return "gmean() arguments should be >=0\n";
}

#endif

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	double x, y, z;
	cout << "Enter two numbers: ";
	while (cin >> x >> y)
	{
		try
		{
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
			cout << "Geomettric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;
			cout << "Enter next set of numbers <q to quit>: ";
		}
		catch (bad_hmean&bg)
		{
			cout << bg.what();
			cout << "Error message:\n" << bg.mesg() << endl;
			cout << "Try again.\n";
			continue;
		}
		catch (bad_gmean&hg)
		{
			cout << hg.what();
			cout << "Error message:\n" << hg.mesg() << endl;
			cout << "Sorry, you don't get to play and more.\n";
			break;
		}
	}
	cout << "Bye!\n";

	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean();
	return 2.0*a*b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean();
	return sqrt(a*b);
}