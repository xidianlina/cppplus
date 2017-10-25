#include <iostream>

double h_avg(double, double);

int main()
{
	using namespace std;

	cout << "Enter two numbers (0 to quit): ";
	double x;
	double y;

	while (cin >> x >> y&&x != 0 && y != 0)
	{
		cout << "average is " << h_avg(x, y) << endl;
		cout << "Enter next two numbers (0 to quit): ";
	}

	return 0;
}

double h_avg(double x, double y)
{
	return 2.0*x*y / (x + y);
}