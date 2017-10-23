#include <iostream>

int main()
{
	using namespace std;

	double sum_Daphne;
	double sum_Cleo;
	sum_Daphne = sum_Cleo = 100.0;
	int year = 0;

	while(sum_Cleo <= sum_Daphne)
	{
		year++;
		sum_Daphne += 10;
		sum_Cleo *= 1.05;
	}

	cout << "After " << year << " years Cleo more than Daphne." << endl;
	cout << "Cleo is " << sum_Cleo << " and Daphne is " << sum_Daphne << ".\n";

	return 0;
}