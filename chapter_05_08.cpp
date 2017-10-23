#include <iostream>
#include <cstring>

int main()
{
	using namespace std;

	char str[20];
	int cnt = 0;
	
	cout << "Enter words (to stop, type the word done):\n";
	cin >> str;
	while (strcmp(str, "done")!=0)
	{
		cnt++;
		cin >> str;
	}
	cout << "You entered a total of " << cnt << " words." << endl;

	return 0;
}