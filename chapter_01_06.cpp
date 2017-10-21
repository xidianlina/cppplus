#include <iostream>

double convert(double);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	cout << "Enter the number of light years: ";
	double light_years;
	cin >> light_years;
	double astro_units;
	astro_units = convert(light_years);
	cout << light_years << " light years = " << astro_units << " astronomical units." << endl;
}

double convert(double light_years)
{
	return 63240 * light_years;
}