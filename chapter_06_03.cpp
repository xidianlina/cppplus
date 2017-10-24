#include <iostream>

using namespace std;

void showmenu();
void carn();
void pianist();
void tree();
void game();

int main()
{
	showmenu();
	char ch;
	while (cin >> ch)
	{
		switch (ch)
		{
			case 'c':
				carn();
				showmenu();
				break;
			case 'p':
				pianist();
				showmenu();
				break;
			case 't':
				tree();
				showmenu();
				break;
			case 'g':
				game();
				showmenu();
				break;
			default:
				cout << "Please enter a c,p,t or g: ";
				break;
		}
	}
	return 0;
}

void showmenu()
{
	cout << "Please enter one of the following choices:\n";
	cout << "c) carnivore    p) pianist\n";
	cout << "t) tree         g) game\n";
}

void carn()
{
	cout << "What is the carnivore?\n";
}

void pianist()
{
	cout << "I am not a pianist!\n";
}

void tree()
{
	cout << "A maple is a tree.\n";
}

void game()
{
	cout << "I want to play the game.\n";
}