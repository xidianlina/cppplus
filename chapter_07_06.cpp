#include <iostream>

using namespace std;

int fill_array(double [], int);
void show_array(const double[], int);
void reverse_array(double *, int);

int main()
{
	cout << "Enter the size of array: ";
	int size;
	cin >> size;
	double *arr = new double[size];

	int n = fill_array(arr, size);
	show_array(arr, n);
	reverse_array(arr, n);
	show_array(arr, n);
	reverse_array(arr + 1, n - 2);
	show_array(arr, n);

	delete[] arr;

	return 0;
}

int fill_array(double arr[], int size)
{
	int i;
	double temp;
	
	for (i = 0; i < size; i++)
	{
		cout << "Enter value #" << i + 1 << ": ";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		arr[i] = temp;
	}

	return i;
}

void show_array(const double arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void reverse_array(double *arr, int n)
{
	double temp = 0;
	
	int i, j;
	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		temp = *(arr + i);
		*(arr + i) = *(arr + j);
		*(arr + j) = temp;
	}
}