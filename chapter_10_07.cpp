#include <iostream>
#include "chapter_10_plorg.h"

int main()
{
	Plorg p("test", 55);
	p.show();
	p.setname("java");
	p.show();
	p.setci(90);
	p.show();

	return 0;
}