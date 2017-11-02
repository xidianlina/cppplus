#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <iterator>
#include <algorithm>

using namespace std;

const int SIZE = 100000;

int main()
{
	clock_t start, end;
	vector<int> vi0(SIZE);
	list<int> li(SIZE);
	srand(time(0));
	for (int i = 0; i < SIZE; i++)
		vi0[i] = rand() % SIZE;
	copy(vi0.begin(), vi0.end(), back_inserter(li));
	vector<int> vi(vi0);

	start = clock();
	sort(vi.begin(), vi.end());
	end = clock();
	cout << "Time of Sort Vector: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

	start = clock();
	li.sort();
	end = clock();
	cout << "Time of Sort List: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

	copy(vi0.begin(), vi0.end(), back_inserter(li));

	start = clock();
	copy(li.begin(), li.end(), back_inserter(vi));
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), back_inserter(li));
	end = clock();
	cout << "Time of Sort List2: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

	return 0;
}