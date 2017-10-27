#include <iostream>
#include "chapter_10_list.h"

void show(Item &item);

int main()
{
	using namespace std;
	List list;
	int data;

	cout << "Enter data: ";
	while (cin >> data)
	{
		if (list.isfull())
		{
			cout << "List already full!\n";
			break;
		}
		else
			list.add(data);
		if (list.isfull())
		{
			cout << "List is full!\nElement is ";
			break;
		}
		else
			cout << "Enter next data (not int to quit): ";
	}
	list.visit(show);
	cout << endl;

	return 0;
}

void show(Item &item)
{
	using std::cout;
	using std::endl;

	cout << item << " ";
}