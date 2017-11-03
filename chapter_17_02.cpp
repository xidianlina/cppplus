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
	ofstream fout(argv[1], ios::out | ios::app);
	if (!fout.is_open())
	{
		cerr << "Can't open " << argv[1] << " file for output.\n";
		exit(EXIT_FAILURE);
	}
	char ch;
	cout << "Enter a char:\n";
	while (cin.get(ch))
	{
		if (ch != '\n')
			fout << ch;
		else
			break;
	}
	fout << endl;
	fout.close();

	return 0;
}