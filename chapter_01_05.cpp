#include <iostream>

double celtofah(double);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	cout << "Please enter a Celsius value: ";
	double cel;
	cin >> cel;
	double fah;
	fah = celtofah(cel);
	cout << cel << " degrees Celsius is " << fah << " degrees Fahrenheit." << endl;

	return 0;
}

double celtofah(double cel)
{
	return 1.8*cel + 32.0;
}