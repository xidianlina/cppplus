#include <iostream>

using namespace std;

double add(double, double);
double subtract(double, double);
double calculate(double, double, double (*pf)(double, double));

int main()
{
	cout << "Enter two doubles: ";
	double x, y;

	while (cin >> x >> y)
	{
		cout << "x + y = " << calculate(x, y, add) << endl;
		cout << "x - y = " << calculate(x, y, subtract) << endl;
		cout << "Next two doubles: ";
	}

	return 0;
}

double add(double x, double y)
{
	return (x + y);
}

double subtract(double x, double y)
{
	return (x - y);
}

double calculate(double x, double y, double (*pf)(double x, double y))
{
	return ((*pf)(x, y));
}