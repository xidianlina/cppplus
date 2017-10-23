#include <iostream>
#include <string>

using namespace std;

struct CandyBar {
	string brand;
	double weight;
	int calory;
};

int main()
{
	CandyBar *snack = new CandyBar[3];

	snack[0].brand = "Abc";
	snack[0].weight = 33.6;
	snack[0].calory = 454;
	snack[1].brand = "DKAD";
	snack[1].weight = 5.54;
	snack[1].calory = 78;
	snack[2].brand = "Jkja";
	snack[2].weight = 98.9;
	snack[2].calory = 45;

	for (int i = 0; i < 3; i++)
	{
		cout << "Brand: " << snack[i].brand << endl;
		cout << "Weight: " << snack[i].weight << endl;
		cout << "Calory: " << snack[i].brand << endl;
	}

	delete[]snack;

	return 0;
}