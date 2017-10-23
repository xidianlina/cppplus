#include <iostream>
#include <string>

int main()
{
	using namespace std;

	const int Months = 12;
	const string months[Months] = { "January","February","March","April","May","June",
		"July","August","September","October","November","December" };

	int sum = 0;
	int *sales = new int[Months];
	for (int i = 0; i < Months; i++)
	{
		cout << "Please enter " << months[i] << " sales: ";
		cin >> sales[i];
		sum += sales[i];
	}
	cout << "The sum of sales is " << sum << endl;

	delete[]sales;

	return 0;
}