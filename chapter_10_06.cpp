#include <iostream>
#include "chapter_10_move.h"

int main()
{
	Move m(2, 3);
	m.showmove();
	m.reset(4, 5);
	m.showmove();
	Move n(9, 8);
	Move t = m.add(n);
	t.showmove();

	return 0;
}