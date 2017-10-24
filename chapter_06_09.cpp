#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct patron
{
	string name;
	double money;
};

int main()
{
	cout << "Enter the filename: ";
	string filename;
	cin >> filename;
	ifstream inFile;
	inFile.open(filename);
	if (!inFile.is_open())
	{
		cout << "Could not open the file " << filename << endl;
		exit(EXIT_FAILURE);
	}
	int num;
	inFile >> num;
	inFile.get();
	patron *ps = new patron[num];
	for (int i = 0; i < num; i++)
	{
		getline(inFile, ps[i].name);
		inFile >> ps[i].money;
		inFile.get();
	}

	int temp = 0;
	cout << "Grand Patrons:\n";
	for(int i=0;i<num;i++)
		if (ps[i].money > 10000)
		{
			cout << ps[i].name << " " << ps[i].money << endl;
			temp++;
		}

	if (temp == 0)
		cout << "none\n";

	temp = 0;
	cout << "Patrons\n";
	for(int i=0;i<num;i++)
		if (ps[i].money <= 10000)
		{
			cout << ps[i].name << " " << ps[i].money << endl;
			temp++;
		}
	if (temp == 0)
		cout << "none\n";

	delete[]ps;

	return 0;
}