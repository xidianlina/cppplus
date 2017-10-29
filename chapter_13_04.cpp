#include "chapter_13_port.h"  

int main()
{
	Port *ptr;
	Port p("Gallo", "tawny", 20);
	ptr = &p;
	ptr->Show();
	std::cout << p << std::endl;
	VintagePort v("Gallo", 20, "tttt", 20);
	ptr = &v;
	ptr->Show();
	std::cout << v << std::endl;

	return 0;
}