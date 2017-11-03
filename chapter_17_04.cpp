#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

const char *file1 = "a.txt";
const char *file2 = "b.txt";
const char *file3 = "c.txt";

int main()
{
	ifstream fin1, fin2;
	fin1.open(file1);
	fin2.open(file2);
	ofstream fout;
	fout.open(file3, ios_base::out | ios_base::trunc);
	string s1, s2;
	if (!fin1.is_open() || !fin2.is_open())
	{
		cerr << "Can't open " << file1 << " or " << file2 << endl;
		exit(EXIT_FAILURE);
	}
	if(!fout.is_open())
	{
		cerr << "Can't open " << file3 << endl;
		exit(EXIT_FAILURE);
	}
	while (!fin1.eof() && !fin2.eof())
	{
		getline(fin1, s1);
		cout << "File1 " << s1 << endl;
		getline(fin2, s2);
		cout << "File2 " << s2 << endl;
		fout << s1 << " " << s2 << endl;
	}
	while (!fin1.eof())
	{
		getline(fin1, s1);
		cout << "More file1 " << s1 << endl;
		fout << s1 << endl;
	}
	while (!fin2.eof())
	{
		getline(fin2, s2);
		cout << "More file2 " << s2 << endl;
		fout << s2 << endl;
	}
	fin1.close();
	fin2.close();
	fout.close();

	return 0;
}