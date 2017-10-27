#ifndef SALES_H_
#define SALES_H_

namespace SALES
{
	class Sales
	{
	private:
		static const int QUARTERS = 4;
		double sales[QUARTERS];
		double sales_average;
		double sales_max;
		double sales_min;
	public:
		Sales();
		Sales(const double *sales, const int n);
		void setSales();
		void showSales()const;
	};
}

#endif