#include <iostream>
#include <cmath>

using namespace std;

const int Inch_Per_Feet = 12;
const double Feet_Per_Meter = 0.0254;
const double Pound_Per_Kg = 2.2;

int main()
{
	cout << "Enter your height in feet and inch:\n";
	cout << "First enter feet: ";
	int feet;
	cin >> feet;
	cout << "Next enter inch: ";
	int inch;
	cin >> inch;
	cout << "Enter your weight in pound: ";
	double pounds;
	cin >> pounds;
	int inches = feet*Inch_Per_Feet + inch;
	double meters = inches*Feet_Per_Meter;
	double kgs = pounds / Pound_Per_Kg;
	double bmi = pow(kgs / meters, 2);

	cout << "BMI is " << bmi << endl;

	return 0;
}