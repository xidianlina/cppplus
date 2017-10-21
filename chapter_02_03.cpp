#include <iostream>

void mice(void);
void run(void);

int main()
{
	mice();
	mice();
	run();
	run();

	return 0;
}

void mice(void)
{
	std::cout << "Three blind mice" << std::endl;
}

void run(void)
{
	std::cout << "See how they run" << std::endl;
}