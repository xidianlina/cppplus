#include <iostream>

const int Size = 30;

struct CandyBar
{
	char brand[Size];
	double weight;
	int calory;
};

int main()
{
	using namespace std;

	CandyBar snack{ "Mocha Munch",2.3,350 };

	cout << "Here is the information of snack:\n";
	cout << "Brand: " << snack.brand << endl;
	cout << "Weight: " << snack.weight << endl;
	cout << "Calory: " << snack.calory << endl;

	return 0;
}