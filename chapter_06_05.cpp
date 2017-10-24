#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter your income: ";
	double income;
	double revenue = 0.0;
	while (cin >> income&&income >= 0)
	{
		if (income <= 5000)
			revenue = 0.0;
		else if (income <= 15000)
			revenue = 0.10*(income - 5000);
		else if (income <= 35000)
			revenue = 0.10*(15000 - 5000) + 0.15*(income - 15000);
		else
			revenue = 0.10*(15000 - 5000) + 0.15*(35000 - 15000) + 0.20*(income - 35000);
		cout << "Revenue is " << revenue << endl;
		cout << "Enter your income: ";
	}

	return 0;
}