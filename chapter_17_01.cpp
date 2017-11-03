#include <iostream>

int main()
{
	using namespace std;

	char ch;
	int cnt = 0;
	cout << "Enter a string (enter $ to quit):\n";
	while (cin.get(ch))
	{
		if (ch != '$')
		{
			cnt++;
			cout << ch;
		}
		else
		{
			cin.putback(ch);
			break;
		}
	}
	cout << endl << cnt << " characters read\n";
	cin.get(ch);
	cout << "Then next input character is " << ch << endl;

	return 0;
}