#include <iostream>

using namespace std;

const int Minute_Per_Degree = 60;
const int Second_Per_Minutes = 60;

int main()
{
	cout << "Enter a latitude in degrees,minutes,and seconds:\n";
	cout << "First,enter the degrees: ";
	int degrees;
	cin >> degrees;
	cout << "Next,enter the minutes of arc: ";
	int minutes;
	cin >> minutes;
	cout << "Finally,enter the seconds of arc: ";
	int seconds;
	cin >> seconds;
	double latitude = degrees + (minutes + seconds / Second_Per_Minutes) / Minute_Per_Degree;
	cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " = "
		<< latitude << " degrees." << endl;

	return 0;
}