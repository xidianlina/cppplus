
#include <iostream>
#include "chapter_10_sales.h"

int main()
{
	double arr[] = { 1.1,2.2,3.3,4.4,5.5,6.6 };
	SALES::Sales sales(arr, 3);
	sales.showSales();
	sales.setSales();
	sales.showSales();

	return 0;
}