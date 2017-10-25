#include <iostream>

int fill_array(int[], int);
void show_array(const int[], int);
double average(const int[], int);

int main()
{
	using namespace std;

	cout << "Enter the size of array (1-10): ";
	int size;
	cin >> size;
	int *arr = new int[size];
	int n = fill_array(arr, size);
	show_array(arr, n);
	cout << "The average of array is " << average(arr, n) << endl;

	delete[]arr;

	return 0;
}

int fill_array(int arr[], int size)
{
	using namespace std;

	int n = 0;
	int temp;

	while (n < size)
	{
		cout << "Enter #" << n + 1 << ": " << endl;
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; enter a number: ";
			break;
		}
		if (temp < 0)
			break;
		arr[n] = temp;
		n++;
	}

	return n;
}

void show_array(const int arr[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

double average(const int arr[], int n)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += arr[i];

	return sum / n;
}