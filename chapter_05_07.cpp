#include <iostream>
#include <string>

using namespace std;

struct car {
	string make;
	int year;
};

int main()
{
	cout << "How many cars do you wish to catalog? ";
	int num;
	cin >> num;

	car *cars = new car[num];
	for (int i = 0; i < num; i++)
	{
		cout << "Car #" << i + 1 << ":\n";
		cout << "Please enter the make: ";
		cin.get();
		getline(cin, cars[i].make);
		cout << "Please enter the year made: ";
		cin >> cars[i].year;
	}

	cout << "Here is your collextion:\n";
	for (int i = 0; i < num; i++)
	{
		cout << cars[i].year << " " << cars[i].make << endl;
	}

	delete[]cars;

	return 0;
}