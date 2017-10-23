#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	int cnt = 0;

	cout << "Enter words (to stop, type the word done):\n";
	cin >> str;
	while (str != "done")
	{
		cnt++;
		cin >> str;
	}
	cout << "You entered a total of " << cnt << " words." << endl;

	return 0;
}