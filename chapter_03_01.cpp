#include <iostream>

const int Inch_Per_Feet = 12;

int main()
{
	using namespace std;

	cout << "Enter your height in inches:___\b\b\b";
	int ht_inch;
	cin >> ht_inch;
	int ht_feet = ht_inch / Inch_Per_Feet;
	int rm_inch = ht_inch%Inch_Per_Feet;
	cout << "Your height is " << ht_feet << " feet(s), " << rm_inch << " inch(es).\n";

	return 0;
}