#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student *ps);
void display3(const student pa[], int n);

int main()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;

	student *ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	
	delete[]ptr_stu;

	cout << "Done\n";

	return 0;
}

int getinfo(student pa[], int n)
{
	int size = n;
	char temp[SLEN];
	
	for (int i = 0; i < n; i++)
	{
		cout << "Enter name: ";
		cin.getline(temp, SLEN);
		bool is_blank = true;
		for(unsigned j=0;j<strlen(temp);j++)
			if (!isspace(temp[j]))
			{
				is_blank = false;
				break;
			}
		if (is_blank)
		{
			size = i;
			break;
		}
		strcpy(pa[i].fullname, temp);
		cout << "Enter hobby: ";
		cin.getline(pa[i].hobby, SLEN);
		cout << "Enter ooplevel: ";
		cin >> pa[i].ooplevel;
		cin.get();
	}
	cout << endl;

	return size;
}

void display1(student st)
{
	cout << "display1 " << st.fullname << " " << st.hobby << " " << st.ooplevel << endl;
}

void display2(const student *pa)
{
	cout << "display2 " << pa->fullname << " " << pa->hobby << " " << pa->ooplevel << endl;
}

void display3(const student pa[], int n)
{
	cout << "display3:\n";
	for (int i = 0; i < n; i++)
		cout << pa[i].fullname << " " << pa[i].hobby << " " << pa[i].ooplevel << endl;
}