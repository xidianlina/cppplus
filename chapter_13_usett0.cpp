#include <iostream>
#include "chapter_13_tabtenn0.h"

int main()
{
	using std::cout;

	TableTennisPlayer player1("Chuck", "Blizzard", true);
	TableTennisPlayer player2("Tara", "Boomdea", false);
	player1.Name();
	if (player1.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";
	player2.Name();
	if (player2.HasTable())
		cout << ": has a table";
	else
		cout << ": hasn't a table.\n";

	return 0;
}