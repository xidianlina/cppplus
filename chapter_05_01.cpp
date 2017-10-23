#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter the start number: ";
	int start;
	cin >> start;
	cout << "Enter the end number: ";
	int end;
	cin >> end;
	
	int sum = 0;
	for (int i = start; i <= end; i++)
		sum += i;
	cout << "The sum is " << sum << endl;

	return 0;
}