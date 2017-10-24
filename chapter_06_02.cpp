#include <iostream>
#include <array>

int main()
{
	using namespace std;

	const int Size = 10;

	int i = 0;
	double val;
	double sum = 0.0;
	array<double, Size> arr;
	while (i<Size&&cin >> val)
	{
		arr[i] = val;
		i++;
		sum += val;
	}
	double avg = sum / i;
	cout << "The average of array is " << avg << endl;

	int cnt = 0;
	for (int j = 0; j < i; j++)
		if (arr[j] > avg)
			cnt++;
	cout << "There are " << cnt << " larger average of array.\n";
}