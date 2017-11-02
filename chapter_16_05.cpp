#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

template <typename T>
int reduce(T arr[], int n);

template <typename T>
void outlong(T n) { cout << n << " "; }

int main()
{
	long a[10] = { 1,3,2,4,7,6,3,4,8,10 };
	int num = reduce(a, 10);
	cout << "Numbers after reduce: " << num << endl;
	string b[10] = { "qwe","ret","qwe","tyu","dfg","jkl","iok","jkl","ads","def" };
	int cnt = reduce(b, 10);
	cout << "Numbers after reduce: " << cnt << endl;

	return 0;
}

template <typename T>
int reduce(T ar[], int n)
{
	list<T> arr;
	arr.insert(arr.begin(), ar, ar + n);
	arr.sort();
	arr.unique();
	for_each(arr.begin(), arr.end(), outlong<T>);
	cout << endl;
	return arr.size();
}