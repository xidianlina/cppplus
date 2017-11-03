#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <cstdlib>

using namespace std;

void ShowStr(const string &);
void GetStrs(ifstream&, vector<string>&);

class Store
{
	ofstream &fout;
public:
	Store(ofstream&os) :fout(os) {}
	void operator()(const string &str);
};

void Store::operator()(const string &str)
{
	size_t len = str.size();
	fout.write((char *)&len, sizeof(size_t));
	fout.write(str.data(), len);
}

int main()
{
	vector<string>vostr;
	string temp;

	cout << "Enter strings (empty line to quit):\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	vector<string>vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);

	return 0;
}

void ShowStr(const string &str)
{
	cout << str << endl;
}

void GetStrs(ifstream&fin, vector<string>&str)
{
	char *s;
	size_t len;

	while (fin.read((char *)&len, sizeof(size_t)))
	{
		s = new char[len];
		fin.read(s, len);
		s[len + 1] = '\0';
		str.push_back(s);
	}
}