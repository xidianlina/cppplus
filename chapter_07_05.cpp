#include <iostream>

long double fab(int num);

int main()
{
	using namespace std;

	cout << "Enter the number: ";
	int num;
	while (cin >> num&&num >= 0)
	{
		cout << fab(num) << endl;
		cout << "Enter next the number: ";
	}
}

long double fab(int num)
{
	if (num == 0)
		return 1;
	
	return num*fab(num - 1);
}