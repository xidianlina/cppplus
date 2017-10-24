#include <iostream>
#include <string>

using namespace std;

struct patron {
	string name;
	double money;
};

int main()
{
	int num;
	int temp = 0;

	cout << "Enter the number of donation: ";
	cin >> num;
	cin.get();
	patron *ps = new patron[num];

	for (int i = 0; i < num; i++)
	{
		cout << "Enter the " << i + 1 << " donation name: ";
		getline(cin, ps[i].name);
		cout << "Enter the " << i + 1 << " donation money: ";
		cin >> ps[i].money;
		cin.get();
	}

	cout << "Grand Patrons:\n";
	for (int i = 0; i<num; i++)
		if (ps[i].money > 10000)
		{
			cout << ps[i].name << " " << ps[i].money << endl;
			temp++;
		}

	if (temp == 0)
		cout << "none\n";

	cout << "Patrons:\n";
	temp = 0;
	for (int i = 0; i<num; i++)
		if (ps[i].money <= 10000)
		{
			cout << ps[i].name << " " << ps[i].money << endl;
			temp++;
		}

	if (temp == 0)
		cout << "none\n";

	delete[]ps;

	return 0;
}