#include <iostream>
#include <cstring>
#include "chapter_10_05stack.h"

int main()
{
	using namespace std;

	Stack st;
	char ch;
	customer cus;
	double total_payment = 0.0;
	cout << "Please enter A to add a customer,\n"
		<< "P to process a PO,or Q to quit.\n";
	while (cin >> ch&&toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
			case 'A':
			case 'a':
				if (st.isfull())
				{
					cout << "stack already full\n";
					cout << "total payment is " << total_payment << endl;
				}
				else
				{					
					cout << "Enter customer fullname: ";
					cin.getline(cus.fullname,35);
					cout << "Enter customer payment: ";
					cin >> cus.payment;
					total_payment += cus.payment;
					st.push(cus);
					cout << "total payment is " << total_payment << endl;
				}
				break;
			case 'P':
			case 'p':
				if (st.isempty())
				{
					cout << "stack already empty\n";
					cout << "total payment is " << total_payment << endl;
				}
				else
				{
					st.pop(cus);
					total_payment -= cus.payment;
					cout << "CUSTOMER #" << cus.fullname << " " << cus.payment << " popped.\n";
					cout << "total payment is " << total_payment << endl;
				}
				break;
		}
		cout << "Please enter A to add a customer,\n"
			<< "P to process a PO,or Q to quit.\n";
	}
	cout << "Bye\n";

	return 0;
}