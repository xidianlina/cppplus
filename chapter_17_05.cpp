#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
#include <fstream>

const char *file1 = "mat.dat";
const char *file2 = "pat.dat";
const char *file3 = "matnpat.dat";

int main()
{
	using namespace std;

	string fname1;
	set<string> mat;
	ifstream finmat, finpat;
	finmat.open(file1);
	finpat.open(file2);
	ofstream fout;
	ostream_iterator<string, char> out1(cout, " "), out2(fout, "\n");
	fout.open(file3, ios_base::out | ios_base::trunc);
	if (!finmat.is_open() || !finpat.is_open())
	{
		cerr << "Can't open " << file1 << " or " << file2 << endl;
		exit(EXIT_FAILURE);
	}
	if (!fout.is_open())
	{
		cerr << "Can't open " << file3 << endl;
		exit(EXIT_FAILURE);
	}
	while (!finmat.eof())
	{
		getline(finmat, fname1);
		mat.insert(fname1);
	}
	cout << "Mat's friends:\n";
	copy(mat.begin(), mat.end(), out1);
	cout << endl;
	string fname2;
	set<string> pat;
	while (!finpat.eof())
	{
		getline(finpat, fname2);
		pat.insert(fname2);
	}
	cout << "Pat's friends:\n";
	copy(pat.begin(), pat.end(), out1);
	cout << endl;
	cout << "Union of Mat and Pat's friends: ";
	set_union(mat.begin(), mat.end(), pat.begin(), pat.end(), out1);
	set_union(mat.begin(), mat.end(), pat.begin(), pat.end(), out2);

	cout << endl;
	finmat.close();
	finpat.close();
	fout.close();

	return 0;
}