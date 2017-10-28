#include <iostream>
#include "chapter_12_cow.h"

using namespace std;

int main()
{
	Cow cow;
	Cow ccc("cow", "grass", 24);
	cow = ccc;
	cow.ShowCow();
	ccc.ShowCow();

	return 0;
}