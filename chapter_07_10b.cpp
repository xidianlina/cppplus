#include <iostream>

using namespace std;

double add(double, double);
double subtract(double, double);
double mean(double, double);
double calculate(double, double, double(*pf)(double, double));

int main()
{
	double x, y;
	double(*pf[3])(double, double) = { add,subtract,mean };
	char *op[3] = { "add","sub","mean" };
	cout << "Enter two doubles: ";
	while (cin >> x >> y)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << op[i] << ": " << x << " and " << y << " = " << calculate(x, y, pf[i]) << endl;
		}
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

double mean(double x, double y)
{
	return (x + y) / 2.0;
}

double calculate(double x, double y, double(*pf)(double x, double y))
{
	return ((*pf)(x, y));
}