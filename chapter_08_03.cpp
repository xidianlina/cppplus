#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void string_toupper(string &);

int main()
{
	cout << "Enter a string (q to quit): ";
	string str;
	while (getline(cin,str))
	{
		if (str.size() == 1 && str[0] == 'q')
			break;
		string_toupper(str);
		cout << "Next string (q to quit): ";
	}
	cout << "Bye.\n";

	return 0;
}

void string_toupper(string &str)
{
	for (unsigned i = 0; i < str.size(); i++)
	{
		if(isalpha(str[i]))
			str[i] = toupper(str[i]);
	}
	cout << str << endl;
}