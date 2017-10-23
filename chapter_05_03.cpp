#include <iostream>

int main()
{
	using namespace std;

	int num;
	int sum = 0;
	cin >> num;
	while (num != 0)
	{
		sum += num;
		cout << "Now, the sum is " << sum << endl;
		cin >> num;
	}

	return 0;
}