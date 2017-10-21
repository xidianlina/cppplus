#include <iostream>

double furlongtoyard(double);

int main()
{
	std::cout << "Enter the distance measured by furlong units: ";
	double fur;
	std::cin >> fur;
	std::cout << "convert the furlong to yard" << std::endl;
	double yard;
	yard = furlongtoyard(fur);
	std::cout << "furlong is " << yard << " yards." << std::endl;

	return 0;
}

double furlongtoyard(double fur)
{
	return 220 * fur;
}