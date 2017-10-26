#include <iostream>
#include "chapter_09_golf.h"

int main()
{
	const int size = 3;
	golf *pgolf = new golf[size];
	int i;
	for (i = 0; i < size; i++)
		if (setgolf(pgolf[i]) == 0)
			break;
	for (int j = 0; j < i; j++)
		showgolf(pgolf[j]);

	golf gf;
	setgolf(gf, "Ann Bird", 24);
	showgolf(gf);
	handicap(gf, 35);
	showgolf(gf);

	return 0;
}