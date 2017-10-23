#include <iostream>

int main()
{
	using namespace std;

	const unsigned int Size = 30;
	cout << "What is your first name? ";
	char fname[Size];
	cin.getline(fname, Size);
	cout << "What is your last name? ";
	char lname[Size];
	cin.getline(lname, Size);
	cout << "What letter grade do you deserve? ";
	char grade;
	cin >> grade;
	cout << "What is your age? ";
	int age;
	cin >> age;
	cout << "Name: " << lname << ", " << fname << endl;
	cout << "Grade: " << char(grade + 1) << endl;
	cout << "Age: " << age << endl;

	return 0;

}