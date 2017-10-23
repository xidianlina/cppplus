#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main()
{
	array<double, 3> ad{ 0 };
	cout << "Enter the three times 40 meters running:" << endl;
	cin >> ad[0] >> ad[1] >> ad[2];

	for (int i = 0; i < 3; i++)
	{
		cout << ad[i] << " ";
	}
	cout << endl;

	double average = (ad[0] + ad[1] + ad[2]) / 3;
	cout << "average is " << average << endl;

	vector<double> vd(3);
	cout << "Please enter the 3 times 40 meters running:\n";
	cin >> vd[0] >> vd[1] >> vd[2];

	double total = 0;
	for (int i = 0; i < 3; i++)
	{
		cout << vd[i] << " ";
		total = vd[i];
	}
	cout << endl;
	double avg = total / 3;

	cout << "avg is " << avg << endl;

	return 0;
}