#include <iostream>
#include <string>

int main()
{
	using namespace std;

	string fname;
	string lname;

	cout << "Enter your first name: ";
	getline(cin, fname);
	cout << "Enter your last name: ";
	getline(cin, lname);

	lname.append(", ").append(fname);

	cout << "Here's the information in a single string: " << lname << endl;

	return 0;
}