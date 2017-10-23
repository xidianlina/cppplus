#include <iostream>

using namespace std;

const int Size = 20;

struct CandyBar {
	char brand[Size];
	float weight;
	int calory;
};

int main()
{
	CandyBar snack[3]{ {"Mocha Munch",2.3,350},{"Tang seng",3.6,85},{"Adk Teng",45.3,54} };

	for (int i = 0; i < 3; i++)
	{
		cout << "Brand: " << snack[i].brand
			 << "\tWeight: " << snack[i].weight
			 << "\tCalory: " << snack[i].calory << endl;
	}

	return 0;
}