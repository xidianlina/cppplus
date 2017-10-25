#include <iostream>

using namespace std;

template <typename T>
T maxn(T[], int);

template <> char * maxn(char *pc[], int n);

int main()
{
	int ai[] = { 3,5,9,7,0,4 };
	double ad[] = { 6.5,2.4,10.9,2.78 };
	char *pc[] = { "one","testing","tail","fighting","go" };

	cout << maxn(ai, 6) << endl;
	cout << maxn(ad, 4) << endl;
	cout << maxn(pc, 5) << endl;

	return 0;
}

template <typename T>
T maxn(T arr[], int n)
{
	T max = arr[0];

	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];

	return max;
}

template <> char * maxn(char *pc[], int n)
{
	char *max = pc[0];

	for (int i = 1; i < n; i++)
		if (strlen(pc[i]) > strlen(max))
			max = pc[i];

	return max;
}