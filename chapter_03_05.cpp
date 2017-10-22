#include <iostream>

using namespace std;

int main()
{
	cout << "Enter the world's population: ";
	long long world_population;
	cin >> world_population;
	cout << "Enter the population of the US:";
	long long us_population;
	cin >> us_population;
	cout << "The population of the US is " << (double)us_population / world_population * 100 << "% of the world population." << endl;

	return 0;
}