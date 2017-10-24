#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	ifstream inFile;
	cout << "Enter the filename: ";
	string filename;
	cin >> filename;
	inFile.open(filename);
	if (!inFile.is_open())
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);
	}
	char ch;
	int cnt = 0;
	inFile >> ch;
	while (inFile.good())
	{
		++cnt;
		inFile >> ch;
	}
	if (inFile.eof())
		cout << "End of file reached.\n";
	else if (inFile.fail())
		cout << "Input terminated by data mismatch.\n";
	else
		cout << "Input terminated for unknown reason.\n";
	cout << "The number of char is " << cnt << endl;

	return 0;
}