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
	double v1;
	double v2;
	explicit bad_hmean(double a = 0, double b = 0, const string &s = "Error in hmean()\n");
	void mesg();
	virtual ~bad_hmean()throw(){}
};

bad_hmean::bad_hmean(double a, double b, const string &s) :v1(a), v2(b), logic_error(s)
{
	name = "hmean";
}
inline void bad_hmean::mesg()
{
	cout << name << "(" << v1 << "," << v2 << ") arguments a=-b should be div a+b=0!\n";
}

class bad_gmean :public bad_hmean
{
private:
	string name;
public:
	explicit bad_gmean(double a = 0, double b = 0, const string &s = "Error in gmean()\n");
	void mesg();
	virtual ~bad_gmean()throw(){}
};

bad_gmean::bad_gmean(double a, double b, const string &s) :bad_hmean(a, b, s)
{
	name = "gmean";
}

inline void bad_gmean::mesg()
{
	cout << name << "(" << bad_gmean::v1 << ", " << bad_hmean::v2 << ") arguments should be >=0\n";
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
		catch(bad_gmean&hg)
		{
			cout << hg.what();
			cout << "Error message:\n";
			hg.mesg();
			cout << endl;
			cout << "Sorry,you don't get to play and more.\n";
			break;
		}
		catch (bad_hmean&bg)
		{
			cout << bg.what();
			cout << "Error message:\n";
			bg.mesg();
			cout << endl;
			cout << "Try again.\n";
			continue;
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