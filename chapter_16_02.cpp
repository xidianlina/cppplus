#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool IsPalindrome(const string);

int main()
{
	cout << "Enter a string (enter quit to quit):\n";
	string str;
	while (getline(cin, str)&&str != "quit")
	{
		if (IsPalindrome(str))
			cout << str << " is palindrome!\n";
		else
			cout << str << " not is palindrome!\n";
		cout << "Enter next a string (enter quit to quit):\n";
	}

	return 0;
}

bool IsPalindrome(string str)
{
	unsigned int i = 0;
	while (i < str.length())
	{
		if (isalpha(str[i]))
		{
			str[i] = tolower(str[i]);
			i++;
		}
		else
			str.replace(i, str.size(), str, i + 1, str.size());
	}		
	cout << str << endl;
	string rev(str.rbegin(), str.rend());
	return rev == str;
}