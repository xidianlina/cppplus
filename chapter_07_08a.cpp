#include <iostream>
#include <vector>
#include <string>

const int Seasons = 4;

const std::vector<std::string> Snames = { "Spring","Summer","Fall","Winter" };

void fill(std::vector<double> *pa);
void show(std::vector<double> da);

int main()
{
	std::vector<double> expenses(Seasons);
	fill(&expenses);
	show(expenses);

	return 0;
}

void fill(std::vector<double> *pa)
{
	for (int i = 0; i < Seasons; i++)
	{
		std::cout << "Enter " << Snames[i] << " expenses: ";
		std::cin >> (*pa)[i];
	}
}

void show(std::vector<double> da)
{
	double total = 0.0;

	std::cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		std::cout << Snames[i] << ": $" << da[i] << std::endl;
		total += da[i];
	}
	std::cout << "Total Expenses: $" << total << std::endl;
}