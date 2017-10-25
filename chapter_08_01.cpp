#include <iostream>

using namespace std;

void show(const char *);
void show(const char *, int);

int main()
{
	char str[] = "hello";
	show(str);
	cout << "Enter times: ";
	int times;
	cin >> times;
	show(str, times);

	return 0;
}

void show(const char *str)
{
	cout << str << endl;
}

void show(const char *str, int n)
{
	if (n == 1)
	{
		cout << str << endl;
	}
	else
	{
		cout << str << endl;
		show(str, --n);
	}
}