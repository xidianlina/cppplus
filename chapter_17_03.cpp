#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[])
{
	using namespace std;

	if (argc == 1)
	{
		cerr << "Usage: " << argv[0] << " filename[s]\n";
		exit(EXIT_FAILURE);
	}

	ifstream fin;
	char ch;
	fin.open(argv[1], ios::in);
	if (!fin.is_open())
	{
		cerr << "Could not open " << argv[1] << endl;
		exit(EXIT_FAILURE);
	}
	
	ofstream fout(argv[2], ios::out | ios::trunc);
	if (!fout.is_open())
	{
		cerr << "Could not open " << argv[1] << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Here are the current contents of the " << argv[1] << " file:\n";
	while (fin.get(ch))
	{
		cout << ch;
		fout << ch;
	}
	fin.close();
	fout.close();

	return 0;
}