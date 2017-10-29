#include "chapter_13_03_dma.h"

const int LEN = 3;

int main()
{
	DMA *p[LEN];

	for (int i = 0; i < LEN; ++i)
	{
		int flag;
		std::cout << "输入要创建的对象，1:lacksDMA 2:hasDMA : ";
		std::cin >> flag;
		if (1 == flag)
		{
			lacksDMA l("Tree", "BLACK",100);
			p[i] = &l;
			p[i]->View();
		}
		else
		{
			hasDMA h("Tree", "OMG", 150);
			p[i] = &h;
			p[i]->View();
		}
	}

	return 0;
}