#include <iostream>

using namespace std;

const int Size = 50;

struct Pizza {
	char company[Size];
	double diameter;
	double weight;
};

int main()
{
	Pizza pie;

	cout << "What is the name of Pizza company: ";
	cin.getline(pie.company, Size);
	cout << "What is the diameter of Pizza: ";
	cin >> pie.diameter;
	cout << "What is the weight of Pizza: ";
	cin >> pie.weight;

	cout << "Company is " << pie.company << endl;
	cout << "Diameter is " << pie.diameter << " inches" << endl;
	cout << "Weight is " << pie.weight << " ounches" << endl;

	return 0;
}