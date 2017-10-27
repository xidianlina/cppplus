#include <iostream>
#include "chapter_10_golf.h"

int main()
{
	Golf golf("Test", 55);
	golf.showGolf();
	golf.setGolf();
	golf.showGolf();
	golf.setHandicap(99);
	golf.showGolf();

	return 0;
}