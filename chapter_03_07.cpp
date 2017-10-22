#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter the automobile gasoline consumption figure in \nEuropean style(liters per 100 kilometers):";
	double euro_style;
	cin >> euro_style;
	cout << "Converts to U.S style(miles per gallon):" << endl;
	cout << euro_style << " L/100KM = " << 62.14*3.875 / euro_style << " mpg\n";

	return 0;
}