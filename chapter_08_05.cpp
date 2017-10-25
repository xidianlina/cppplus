#include <iostream>

using namespace std;

template <typename T>
T max5(T[], int n=5);

int main()
{
	int arri[5] = { 6,2,4,7,0 };
	double arrd[5] = { 5.3,9.5,4.2,10.9,1.5 };
	cout << max5(arri) << endl;
	cout << max5(arrd) << endl;

	return 0;
}

template <typename T>
T max5(T arr[], int n)
{
	T max = arr[0];
	
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];

	return max;
}