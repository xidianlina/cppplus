#include <iostream>

double * fill_array(double *, int);
void show_array(const double *, const double *);
void revalue(double r, double *, double *);

int main()
{
	using namespace std;
	
	cout << "Enter the size of array: ";
	int size;
	cin >> size;
	double *arr = new double[size];

	double *end = fill_array(arr, size);
	show_array(arr, end);
	if (end)
	{
		cout << "Enter revaluation factor: ";
		double factor;
		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; Please enter a number: ";
		}
		revalue(factor, arr, end);
		show_array(arr, end);
	}
	cout << "Done.\n";
	
	return 0;
}

double *fill_array(double *begin, int size)
{
	using namespace std;

	double temp;
	double *ps;
	int i = 0;

	for(ps=begin;i<size,ps!=(begin+size);ps++,i++)
	{
		cout << "Enter #" << i + 1 << ": ";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (temp < 0)
			break;
		*ps = temp;
	}

	return ps;
}

void show_array(const double *begin, const double *end)
{
	for (const double *ps = begin; ps != end; ps++)
		std::cout << "Property : $" << *ps << std::endl;
}

void revalue(double r, double *begin, double *end)
{
	for (double *ps = begin; ps != end; ps++)
		*ps *= r;
}