#include <iostream>

void show_time(int, int);

int main()
{
	using namespace std;

	cout << "Enter the number of hours: ";
	int hours;
	cin >> hours;
	cout << "Enter the number of minutes: ";
	int minutes;
	cin >> minutes;
	show_time(hours, minutes);

	return 0;
}

void show_time(int hours, int minutes)
{
	using namespace std;

	cout << "Time: " << hours << ":" << minutes << endl;
}