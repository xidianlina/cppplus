#include <iostream>
#include <string>

int main()
{
	using namespace std;

	const int Months = 12;
	const string months[Months] = { "January","February","March","April","May","June",
			"July","August","September","October","November","December" };

	int (*sales)[Months] = new int[3][Months];	
	int sum_total = 0;

	for (int i = 0; i < 3; i++)
	{
		int sum_year = 0;
		for (int j = 0; j < Months; j++)
		{
			cout << "The " << i+1 << " year " << months[j] << " sales is:";
			cin >> sales[i][j];
			sum_year += sales[i][j];
		}
		sum_total += sum_year;
		cout << "The sum sales of " << i+1 << " year is " << sum_year << endl;
	}
	cout << "The 3 years sum sales is " << sum_total << endl;

	delete[]sales;

	return 0;
}