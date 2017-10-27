#include <iostream>
#include "chapter_10_list.h"

bool List::add(const Item item)
{
	if (isfull())
		return false;
	else
	{
		data[length++] = item;
		return true;
	}
}

bool List::isempty() const
{
	return length == 0;
}

bool List::isfull() const
{
	return length == SIZE;
}

void List::visit(void(*pf)(Item &elem))
{
	for(int i=0;i<length;i++)
		(*pf)(data[i]);
}