#include <iostream>
#include <string>

const int Seasons = 4;
const std::string Snames[Seasons] = { "Spring","Summer","Fall","Winter" };

void fill(double (*pa)[Seasons]);
void show(const double da[],int n);

int main()
{
	double expenses[Seasons];
	fill(&expenses);
	show(expenses,Seasons);

	return 0;
}

void fill(double(*pa)[Seasons])
{
	for (int i = 0; i < Seasons; i++)
	{
		std::cout << "Enter " << Snames[i] << " expenses: ";
		std::cin >> (*pa)[i];
	}
}

void show(const double da[], int n)
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