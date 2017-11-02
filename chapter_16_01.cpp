#include <iostream>
#include <string>

using namespace std;

bool IsPalindrome(const string);

int main()
{
	cout << "Enter a string (enter quit to quit):\n";
	string str;
	while (cin >> str&&str != "quit")
	{
		if (IsPalindrome(str))
			cout << str << " is palindrome!\n";
		else
			cout << str << " not is palindrome!\n";
		cout << "Enter a string (enter quit to quit):\n";
	}

	return 0;
}

bool IsPalindrome(const string str)
{
	string rev(str.rbegin(), str.rend());
	return rev == str;
}