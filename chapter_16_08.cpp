#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

int main()
{
	using namespace std;

	ostream_iterator<string, char> out(cout, " ");

	string fname1;
	set<string> Mat;
	cout << "Enter Mat's friends (enter quit to quit):\n";
	while (getline(cin, fname1) && fname1 != "quit")
	{
		Mat.insert(fname1);
		cout << "Enter Mat's friends (enter quit to quit):\n";
	}
	cout << "Mat's friends:\n";
	copy(Mat.begin(), Mat.end(), out);
	cout << endl;
	
	string fname2;
	set<string> Pat;
	cout << "Enter Pat's friends (enter quit to quit):\n";
	while (getline(cin, fname2) && fname2 != "quit")
	{
		Pat.insert(fname2);
		cout << "Enter Pat's friends (enter quit to quit):\n";
	}
	cout << "Pat's friends:\n";
	copy(Pat.begin(), Pat.end(), out);
	cout << endl;

	cout << "Union of Mat and Pat friends: ";
	set_union(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(), out);
	cout << endl;

	return 0;
}