#include <iostream>
#include "chapter_10_move.h"

Move::Move(double a, double b)
{
	x = a;
	y = b;
}

void Move::showmove() const
{
	std::cout << "(" << x << "," << y << ")" << std::endl;
}

Move Move::add(const Move &m) const
{
	Move tmp((*this).x + m.x, (*this).y + m.y);
	return tmp;
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
}