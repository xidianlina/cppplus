#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

vector<int> Lotto(int l1, int l2);
void Show(int n);

int main()
{
	vector<int> winners;
	winners = Lotto(51, 6);
	for_each(winners.begin(), winners.end(), Show);

	return 0;
}

vector<int> Lotto(int l1, int l2)
{
	vector<int> nums;
	vector<int> nums2;
	srand(time(0));
	for (int i = 0; i < l1; i++)
		nums.push_back(i);
	random_shuffle(nums.begin(), nums.end());
	for (int i = 0; i < l2; i++)
		nums2.push_back(nums[rand() % l1] + 1);
	return nums2;
}

void Show(int n)
{
	cout << "The winner is " << n << endl;
}