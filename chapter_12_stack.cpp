#include "chapter_12_stack.h"

Stack::Stack(int n)
{
	pitems = new Item[n];
	size = n;
	top = 0;
}
Stack::Stack(const Stack &st)
{
	pitems = new Item[st.size];
	size = st.size;
	for (top = 0; top < size; top++)
		pitems[top] = st.pitems[top];
}
Stack::~Stack()
{
	delete[]pitems;
	pitems = NULL;
	size = top = 0;
}
bool Stack::isempty()const
{
	return top == 0;
}
bool Stack::isfull()const
{
	return top == size;
}
bool Stack::push(const Item &item)
{
	if (top < MAX)
	{
		pitems[top++] = item;
		return true;
	}
	else
		return false;
}
bool Stack::pop(Item &item)
{
	if (top > 0)
	{
		item = pitems[--top];
		return true;
	}
	else
		return false;
}
Stack & Stack::operator=(const Stack &st)
{
	if (this == &st)
		return *this;
	pitems = new Item[st.size];
	size = st.size;
	for (top = 0; top < size; top++)
		pitems[top] = st.pitems[top];
	return *this;
}
std::ostream &operator<<(std::ostream &os, const Stack &st)
{
	os << "Stack contains: " << std::endl;
	for (int i = 0; i < st.top; i++)
		os << st.pitems[i] << "\t";
	return os;
}