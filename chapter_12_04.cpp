#include "chapter_12_stack.h"

int main()
{
	Stack st;
	Item it[10];
	for (int i = 0; i < 10; i++)
	{
		it[i] = i + 1;
		st.push(it[i]);
	}
	std::cout << st;

	Stack s(st);
	std::cout << "new stack is: " << s;
	Stack copystack = s;
	std::cout << "copy stack is: " << copystack;

	return 0;
}