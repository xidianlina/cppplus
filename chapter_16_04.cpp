#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int reduce(long ar[], int n);
void outlong(int n) { cout << n << " "; }

int main()
{
	long a[10] = { 1,3,2,4,7,6,3,4,8,10 };
	int nums = reduce(a, 10);
	cout << "Numbers after reduce: " << nums << endl;

	return 0;
}

int reduce(long ar[], int n)
{
	list<long> arr;
	arr.insert(arr.begin(), ar, ar + n);
	arr.sort();
	arr.unique();
	for (long x : arr)
		outlong(x);
	cout << endl;

	return arr.size();
}