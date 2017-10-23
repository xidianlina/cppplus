#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

int main()
{
	using namespace std;

	const int Size = 30;
	char fname[Size];
	char lname[Size];

	cout << "Enter your first name: ";
	cin.getline(fname, Size);
	cout << "Enter your last name:";
	cin.getline(lname, Size);
	strcat(lname, ", ");
	strncat(lname, fname, Size);
	cout << "Here's the information in a single string: " << lname << endl;

	return 0;
}