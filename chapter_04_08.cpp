#include <iostream>

const int Size = 50;

struct Pizza
{
	char company[Size];
	double diameter;
	double weight;
};

int main()
{
	using namespace std;

	Pizza *ps = new Pizza;

	cout << "Enter the diameter of pizza: ";
	cin >> ps->diameter;
	cin.get();
	cout << "Enter the name of company: ";
	cin.get(ps->company, Size);
	cout << "Enter the weight of pizza: ";
	cin >> ps->weight;

	cout << "Diameter is " << ps->diameter << endl;
	cout << "Company is " << ps->company << endl;
	cout << "Weight is " << ps->weight << endl;

	delete ps;

	return 0;
}