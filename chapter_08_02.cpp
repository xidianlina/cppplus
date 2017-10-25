#include <iostream>

using namespace std;

struct CandyBar {
	char *brand;
	double weight;
	int calory;
};

void set_candyBar(CandyBar &cb, char *brand = "Millennium Munch", double weight = 2.85, int calory = 350);
void show_candyBar(const CandyBar &);

int main()
{
	CandyBar cb;
	char *brand = "Test Candy";
	double weight = 45.25;
	int calory = 370;
	set_candyBar(cb);
	show_candyBar(cb);
	set_candyBar(cb, brand, weight, calory);
	show_candyBar(cb);

	return 0;
}

void set_candyBar(CandyBar &cb, char *brand, double weight, int calory)
{
	cb.brand = brand;
	cb.weight = weight;
	cb.calory = calory;
}

void show_candyBar(const CandyBar &cb)
{
	cout << cb.brand << endl;
	cout << cb.weight << endl;
	cout << cb.calory << endl;
}