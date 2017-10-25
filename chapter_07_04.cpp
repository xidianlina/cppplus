#include <iostream>

using namespace std;

long double probability(unsigned numbers, unsigned picks);

int main()
{
	double total, choices, special;
	cout << "Enter the total number of choices on the game card \n"
		    "the number of picks and the number of special allowed:\n";
	while ((cin >> total >> choices >> special) && choices <= total&&special <= total)
	{
		cout << "You have one chance n ";
		cout << probability(total, choices)*probability(special, 1);
		cout << " of winning.\n";
		cout << "Next three numbers (q to quit): ";
	}
}

long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0;
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result*n / p;

	return result;
}