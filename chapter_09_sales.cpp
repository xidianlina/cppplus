#include <iostream>
#include "chapter_09_sales.h"

namespace SALES
{
	using std::cout;
	using std::cin;
	using std::endl;

	void setSales(Sales &s, const double ar[], int n)
	{
		double max = 0;
		double min = 9999;
		double average = 0.0;
		if (n <= QUARTERS)
		{
			for (int i = 0; i < n; i++)
				s.sales[i] = ar[i];
			for (int i = 0; i < n; i++)
			{
				max = max > s.sales[i] ? max : s.sales[i];
				min = min < s.sales[i] ? min : s.sales[i];
				average += s.sales[i];
			}
			s.max = max;
			s.min = min;
			s.average = average / n;
		}
		else
		{
			for (int i = 0; i < QUARTERS; i++)
				s.sales[i] = ar[i];
			for (int i = 0; i < QUARTERS; i++)
			{
				max = max > s.sales[i] ? max : s.sales[i];
				min = min < s.sales[i] ? min : s.sales[i];
				average += s.sales[i];
			}
			s.max = max;
			s.min = min;
			s.average = average / QUARTERS;
		}
	}

	void setSales(Sales &s)
	{
		double max = 0;
		double min = 9999;
		double average = 0.0;
		for (int i = 0; i < QUARTERS; i++)
		{
			cout << "Enter a double: ";
			cin >> s.sales[i];
			max = max > s.sales[i] ? max : s.sales[i];
			min = min < s.sales[i] ? min : s.sales[i];
			average += s.sales[i];
		}
		s.max = max;
		s.min = min;
		s.average = average / QUARTERS;
	}

	void showSales(const Sales &s)
	{
		for (int i = 0; i < QUARTERS; i++)
			cout << s.sales[i] << " ";
		cout << endl << "max is " << s.max << endl << "min is " << s.min << endl << "average is " << s.average << endl;
	}
}